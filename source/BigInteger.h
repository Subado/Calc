/* BigInteger is a class that stores integer unlimited numbers.
 * One digit of a number is stored in 4 bits.
 * Also bytes are located from right to left. */
#include <cstdint>
#include <vector>
#include <string>
#include <iostream>

class BigInteger
{
	bool sign;
	size_t length;
	std::vector<uint8_t> digits;
public:
	BigInteger();
	BigInteger(const std::string &source);

	const size_t &size() const { return length; };

	const BigInteger &operator = (const std::string &source);

	bool operator > (const BigInteger &other);
	bool operator >= (const BigInteger &other);
	bool operator < (const BigInteger &other);
	bool operator <= (const BigInteger &other);

	bool operator == (const BigInteger &other);
	bool operator == (const std::string &other);
	bool operator != (const BigInteger &other);
	bool operator != (const std::string &other);

	BigInteger operator + (const BigInteger &other);

	friend std::ostream &operator << (std::ostream &out, const BigInteger &num);
	friend void stringToBigInteger(std::string source, BigInteger &dest);
	friend BigInteger stringToBigInteger(const std::string &source);
};

bool isanum(const std::string &str);
