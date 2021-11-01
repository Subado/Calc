#include <cstdint>
#include <vector>
#include <string>
#include <iostream>

class BigInteger
{
	size_t size;
	std::vector<int8_t> digits;
public:
	BigInteger(const std::string &source);

	friend std::ostream &operator << (std::ostream &out, const BigInteger &num);
};
