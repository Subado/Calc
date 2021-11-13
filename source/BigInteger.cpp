#include "BigInteger.h"
#include <regex>
#include <cstddef>

BigInteger::BigInteger(const std::string &source)
	: length{ 0 }
{
	stringToBigInteger(source, *this);
}

const BigInteger &BigInteger::operator = (const BigInteger &other)
{
	length = other.length;
	digits = other.digits;

	return *this;
}

std::ostream &operator << (std::ostream &out, const BigInteger &num)
{
	for (size_t i = num.length - 1, j = num.digits.size() - 1; i != size_t(-1); i--)
	{
		if (i % 2 == 0)
		{
			out << (num.digits[j] & 0x0f);
			j--;
		}
		else
		{
			out << (num.digits[j] >> 4);
		}
	}

	return out;
}

void stringToBigInteger(std::string source, BigInteger &dest)
{
	std::reverse(source.begin(), source.end());

	size_t i;
	for (i = 0; i < source.length(); i++)
	{
		if (!(std::regex_match(std::string(1, source[i]), std::regex("[0-9]")))) // Checking that all chars are digits.
		{
			dest.digits.clear();
			break;
		}
		else if (i % 2 == 0)
		{
			dest.digits.push_back(source[i] - 48);
		}
		else
		{
			dest.digits[dest.digits.size() - 1] |= ((source[i] - 48) << 4);
		}
	}

	dest.length = i;
}
