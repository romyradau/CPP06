# include "../incl/Base.hpp"
#include "../incl/A.hpp"
#include "../incl/B.hpp"
#include "../incl/C.hpp"

Base::~Base(){

}
//if you have a virtual deconstructor you somehow need to implement it

Base * generate(void){

	switch(arc4random() % 3){

		case 0:
			return (new A);
		case 1:
			return (new B);
		default:
			return (new C);
	}
}


void identify(Base* p){

	if(dynamic_cast<A*>(p))
		std::cout << "it's A\n";
	else
		std::cout << " Pointer Conversion to A not possible\n";
	if (dynamic_cast<B*>(p))
		std::cout << "it's B\n";
	else
		std::cout << " Pointer Conversion to B not possible\n";
	if(dynamic_cast<C*>(p))
		std::cout << "it's C\n";
	else
		std::cout << " Pointer Conversion to C not possible\n";
}

void identify(Base& p){

	try{
		A& aRef = dynamic_cast<A&>(p);
		std::cout << "it's A\n";
	}
	catch(std::bad_cast &bc){

		std::cout << " Reference Conversion to A not possible	" << bc.what() << std::endl;
	}
	try{
		B& bRef = dynamic_cast<B&>(p);
		std::cout << "it's B\n";
	}
	catch(std::bad_cast &bc){

		std::cout << " Refernece Conversion to B not possible	" << bc.what() << std::endl;
	}
	try{
		C& cRef = dynamic_cast<C&>(p);
		std::cout << "it's C\n";
	}
	catch(std::bad_cast &bc){

		std::cout << " Reference Conversion to C not possible	" << bc.what() << std::endl;
	}
}
