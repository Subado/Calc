#include "BigInteger.h"
#include <regex>
#include <sstream>
#include <cstddef>

BigInteger::BigInteger() : length{ 0 }
{
}

BigInteger::BigInteger(const std::string &source)
	: BigInteger()
{
	stringToBigInteger(source, *this);
}

const BigInteger &BigInteger::operator = (const std::string &source)
{
	stringToBigInteger(source, *this);

	return *this;
}

bool BigInteger::operator > (const BigInteger &other)
{
	if (length > other.length)
	{
		return true;
	}
	else if (other.length > length)
	{
		return false;
	}

	for (size_t i = digits.size() - 1; i != size_t(-1); i--)
	{
		if (other.digits[i] > digits[i])
		{
			return false;
		}
	}

	return true;
}

bool BigInteger::operator >= (const BigInteger &other)
{
	if (length > other.length)
	{
		return true;
	}
	else if (other.length > length)
	{
		return false;
	}

	for (size_t i = digits.size() - 1; i != size_t(-1); i--)
	{
		if (digits[i] < other.digits[i])
		{
			return false;
		}
	}

	return true;
}

bool BigInteger::operator == (const BigInteger &other)
{
	if (length != other.length)
	{
		return false;
	}
	else if (digits != other.digits)
	{
		return false;
	}

	return true;
}

bool BigInteger::operator == (const std::string &other)
{
	if (!isanum(other))
	{
		throw -1;
	}

	std::ostringstream tmp;
	tmp << *this;

	if (length != other.length())
	{
		return false;
	}
	else if (tmp.str() != other)
	{
		return false;
	}

	return true;
}

bool BigInteger::operator != (const BigInteger &other)
{
	if (length != other.length)
	{
		return true;
	}
	else if (digits != other.digits)
	{
		return true;
	}

	return false;
}

bool BigInteger::operator != (const std::string &other)
{
	if (!isanum(other))
	{
		throw -1;
	}

	std::ostringstream tmp;
	tmp << *this;

	if (length != other.length())
	{
		return true;
	}
	else if (tmp.str() != other)
	{
		return true;
	}

	return false;

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
			throw -1;
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

BigInteger stringToBigInteger(const std::string &source)
{
	BigInteger dest;
	stringToBigInteger(source, dest);
	return dest;
}


bool isanum(const std::string &str)
{
	for (size_t i = 0; i < str.length(); i++)
	{
		if (!(std::regex_match(std::string(1, str[i]), std::regex("[0-9]")))) // Checking that all chars are digits.
		{
			return false;
		}
	}

	return true;
}
