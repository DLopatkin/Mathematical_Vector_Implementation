#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <numeric>
#include <iterator>
#include <new>

template < class T > class vect {
	std::vector < T >* m;

 public:
 	vect():m(NULL) {}

	// overloaded constructor
 	vect(size_t n)
	{
		m = new std::vector< T >( n );
	}

 	vect(std::vector < T > v)
	{
	m = new std::vector< T >(v);
	}

	// copy constructor
	vect(const vect < T > &v)
	{
		m = new std::vector< T >( *( v.m) );
	}

	// destructor
	~vect()
	{
		delete m;
	}

	std::vector < T > getData() const{
		return *m;
	} 
	
	size_t size() const {
		return m->size();
	} 
	
	void addTo(T value) {
		if ( m != NULL)
		m->push_back(value);
	}

	void addAt(T value, size_t loc = 0) {
		m->emplace(m.begin() + loc, value);
	}

	void rmFrom() {
		m->pop_back();
	}

	void rmAt(size_t loc) {
		m->erase(m.begin() + loc);
	}

	double sum() const {
		// calculate the sum of the vectors elements
		double sum = std::accumulate(m->begin(), m->end());
		return sum;
	}
	
	double scalarMult() const {
		vect < T > temp = *this;
		double res = 0;
		size_t l = 0;
		size_t s = m->size;
		while (l < s) {
			res += temp[l] * temp[l];
			l++;
		}
		return res;
	}

	double scalarMult(vect < T > other) const {
		vect < T > temp = *this;
		double res = 0;
		size_t l = 0;
		size_t s = m->size();
		while (l < s) {
			res += temp[l] * other[l];
			l++;
		} 
		return res;
	}

	double length() const {
		return sqrt(this->scalarMult());
	} 
	
	vect < T > diff(vect < T > other) {
		vect < T > diff;
		return (*this - other);
	}

	double angle(vect < T > other) const {
		double value =
		    this.scalarMult(other) / (this.lenght * other.lenght);
		 value = acos(value);
		 return value;
	} 

	bool is_perpendicular(vect < T > other) {
		return (this->scalarMult(other) == 0);
	}

	vect < T > parallel_comp(vect < T > other) {
		// projection of other onto *this
		vect < T > temp = *this;
		return (temp.scalarMult(other) / temp.scalarTemp(temp)) * temp;
	}

	vect < T > normal_comp(vect < T > other) {
		return other - parallel_comp(other);
	}

	// overloaded operators
	vect < T > &operator=(vect < T > other) {
		other.swap(*this);
		return *this;
	}

	T & operator[](size_t i) {
		return m->data()[i];
	}
	
	const T & operator[] (size_t i) const {
		return m[i];
	}
};


template <class T>
void swap(vect < T > &a, vect < T > &b) {
	using std::swap;		
	swap(a.m, b->m);
}

template < class T >
    std::ostream & operator<<(std::ostream & os, const vect < T > &v)
{
	os << v.size() << ": ";
	for (int i = 0; i < v.size(); i++) {
		os << v.getData()[i] << " ";
	}
	return os;
}

template < class T > std::istream & operator>>(std::istream & is, vect < T > &v)
{
	std::size_t s = 0;
	char marker = 'B';

	if (is >> s >> marker) {
		if (marker != ':') {
			is.setstate(std::ios::failbit);
		} else {
			T value;
			for (; s > 0 && (is >> value); --s) {
				v.addTo(value);
			}
		}
	}
	return is;
}

template < class T > vect < T > &operator+=(vect < T > &a, const vect < T > &b)
{
	for (size_t i = 0; i < a.size(); ++i)
		a[i] += b[i];
	return a;
}

template < class T > vect < T > operator+(const vect < T > &a,
					  const vect < T > &b)
{
	vect < T > z(a.size());
	for (size_t i = 0; i < a.size(); ++i)
		z[i] = a[i] + b[i];
	return z;
}
