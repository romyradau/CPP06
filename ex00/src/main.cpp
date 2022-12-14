
# include "../incl/Converter.hpp"

int main(int argc, char *argv[]){

	try{
		if (argc != 2){
			throw std::invalid_argument("wrong number of arguments");
		}
		Converter Caster(argv[1]);
		Converter::TYPE type = Caster.whichType(argv[1]);
		switch(type){
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
	return (0);
}
