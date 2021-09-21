#include <cstdint>
#include <vector>
#include <string>

// Класс для хранения вещественных чисел с идеальной точностью и для проведения операций с этими числамии.
class BigDecimal
{
	std::vector<int8_t> number; // В этом векторе хранится число. Одна цифра записывается в 4 бита( тетрад ).

public:

	BigDecimal(std::string source);

	friend void toBigDecimal(BigDecimal &destination, std::string source);
};
