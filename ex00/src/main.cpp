
# include "../incl/Converter.hpp"

int main(int argc, char *argv[]){

	if (argc != 2){
		std::cout << "wrong input\n" << std::endl;
		exit(1);
		//stattdessen hier 
		//throw std::invalid_argument("wrong number of arguments");
	}
	Converter Caster;
	//Caster.whichType gibt enum zuruck mit der wir dann in die einzelnen Fälle können
	switch(Caster.whichType(argv[1])){
		//range fur overflow einbauen
		case Caster.CHAR:
			Caster.convert_char();
		case Caster.INT:
			Caster.convert_int();
		case Caster.DOUBLE:
			Caster.convert_double();
		case Caster.FLOAT:
			Caster.convert_float();
			//braucht dann nochmal subfunctions die 
			//oder anderer aufbau, dass man erstmal nur ne enum zuruckgibt?
	}



	
		
}
//machen member function pointer hier ueberhaupt sinn?