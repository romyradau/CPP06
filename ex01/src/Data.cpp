# include "../incl/Data.hpp"

uintptr_t serialize(Data* ptr){

	return reinterpret_cast<uintptr_t>(ptr);
}
//unsigned integer type capable of holding a pointer to void

Data* deserialize(uintptr_t raw){

	return reinterpret_cast<Data*>(raw);
}
