#include <cstdint>
#include <vector>
#include <string>
#include <iostream>

class BigInteger
{
	size_t size;
	std::vector<uint8_t> digits;
public:
	BigInteger(const std::string &source);

	const BigInteger &operator = (const BigInteger &other);
	friend std::ostream &operator << (std::ostream &out, const BigInteger &num);
};
