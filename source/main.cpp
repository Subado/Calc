#include <iostream>
#include <ctime>
#include "BigInteger.h"

// Generates a string containing random digits.
std::string genRandStrNum()
{
	std::string str{};
	size_t size = rand() % 15 + 1;
	for (size_t i = 0; i < size; i++)
	{
		str += 48 + rand() % 10;

		if (!((str[i] - 48) && i) && !((str[i] - 48) || i))
		{
			str[i] = 48 + rand() % 9 + 1;
		}
	}

	return str;
}

int main()
{
    srand(time(0));
	std::cout << '\n' << "sead = " << time(0) << "\n\n";

	std::string s1{ genRandStrNum() }, s2{ genRandStrNum() };
	BigInteger n1(s1), n2(s2);

	std::cout << '\n' << ((n1 == s1) ? ("[OK]") : ("[ERR]")) << "\ns1: " << s1 << "\nn1: " << n1 << "\n\n\n" <<
		((n2 == s2) ? ("[OK]") : ("[ERR]")) << "\ns2: " << s2 << "\nn2: " << n2 << "\n\n" <<
		"n1 > n2 == " << std::boolalpha << (n1 > n2) << "\n\n";
	return 0;
}
