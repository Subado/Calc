#include <iostream>
#include <ctime>
#include "BigInteger.h"

// Generates a string containing random digits.
std::string genRandStrNum()
{
	std::string str{};

	for (size_t i = 0; i < rand() % 15 + 1; i++)
	{
		str += 48 + rand() % 10;

		if (!((str[i] - 48) && i) && !((str[i] - 48) || i))
		{
			str[i] = rand() % 9 + 1;
		}
	}

	return str;
}

int main()
{
	srand(time(0));

	std::string s1{ genRandStrNum() }, s2{ genRandStrNum() };
	BigInteger n1(s1), n2(s2);

	std::cout << '\n' << s1 << '\n' << n1 << "\n\n" <<
		s2 << '\n' << n2 << '\n';
	return 0;
}
