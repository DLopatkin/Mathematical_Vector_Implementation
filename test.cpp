#include<iostream>
#include"vector.hpp"

int main(void)
{
	std::vector<double> k;
	vect<double> b(1);
	k.push_back(1.0);
	k.push_back(2.0);
	vect<double> a(k);
	std::cout <<"Vector A "<< a << std::endl;
	std::cout <<"Enter A addition " << std::endl;
	std::cin >> a;
	std::cout <<"Enter vector B " << std::endl;
	std::cin >> b;
	std::cout <<"New Vector A "<< a << std::endl;
	std::cout <<"A*B " <<  a.scalarMult(b) << std::endl;
	return 0;
}
