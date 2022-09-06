
# include "../incl/Converter.hpp"

int main(int argc, char *argv[]){

	try{
		if (argc != 2){
			throw std::invalid_argument("wrong number of arguments");
		}
		Converter Caster(argv[1]);
		Converter::TYPE type = Caster.whichType(argv[1]);

		// if (Caster._inf || Caster._inff)
		// 	std::cout << infinity_display(argv[1]) << std::endl;
		switch(type){
			// case Caster.PSEUDO:
			// 	Caster.convert_pseudo(argv[1]); break;
			case Caster.CHAR:
				Caster.convert_char(argv[1]); break;
			case Caster.INT:
				Caster.convert_int(argv[1]); break;
			case Caster.DOUBLE:
				Caster.convert_double(argv[1]); break;
			case Caster.FLOAT:
				Caster.convert_float(argv[1]); break;
			case Caster.ERR:
				throw Converter::Impossible(); break;

		}
		std::cout << Caster << std::endl;	
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;
	};
}
