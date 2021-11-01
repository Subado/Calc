#include "BigInteger.h"
#include <regex>
#include <cstddef>

BigInteger::BigInteger(const std::string &source)
	: size{ 0 }
{
	size_t i;
	for (i = 0; i < source.size(); i++)
	{
		if (!(std::regex_match(std::string(1, source[i]), std::regex("[0-9]"))))
		{
			digits.clear();
			break;
		}
		else if (i % 2 == 0)
		{
			digits.push_back((source[i] - 48) << 4);
		}
		else
		{
			digits[digits.size() - 1] |= source[i] - 48;
		}
	}
	size = i;
}

std::ostream &operator << (std::ostream &out, const BigInteger &num)
{
	for (size_t i = 0, j = 0; i < num.size; i++)
	{
		if (i % 2 == 0)
		{
			out << (num.digits[j] >> 4);
		}
		else
		{
			out << (num.digits[j] & 0x0F);
			j++;
		}
	}

	return out;
}
