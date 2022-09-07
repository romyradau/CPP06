#include <cstdint>
#include <iostream>
#include <iomanip>

struct Data{

	unsigned int	uint;
	int				value;
};

uintptr_t serialize(Data* ptr);

Data* deserialize(uintptr_t raw);
