#include "../incl/Base.hpp"
#include "../incl/A.hpp"
#include "../incl/B.hpp"
#include "../incl/C.hpp"


void check_leaks(){

	system("leaks dynamic");
}
int	main(){

	for (int i = 0; i < 3; i++){

		Base * randomPtr = generate();
		Base& refRandomBase = *randomPtr;
		identify(randomPtr);
		identify(refRandomBase);
		delete randomPtr;
		std::cout << std::endl;
	}
		atexit(check_leaks);
		return (0);
}