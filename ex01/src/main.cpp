# include "../incl/Data.hpp"


int main(){

	Data * dataPtr = new Data;
	dataPtr->value = -42;
	dataPtr->uint = 42;

	Data * comparePtr = deserialize(serialize(dataPtr));

	std::cout << "dataPtr->value:		" << dataPtr->value << '\n'
	<< "dataPtr->uint:		" << dataPtr->uint << '\n'
	<< "comparePtr->value: 	" <<  comparePtr->value << '\n'
	<< "comparePtr->uint:	" <<  comparePtr->uint << '\n' << std::endl;
	return (0);
}