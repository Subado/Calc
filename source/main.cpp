#include <iostream>
#include "BigInteger.h"

int main()
{
	BigInteger n1("1420");
	BigInteger n2("999");
	std::cout << n2 << '\n';
	n2 = n1;
	std::cout << n2 << '\t' << n1 << '\n';

	return 0;
}
