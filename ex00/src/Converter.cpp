# include "../incl/Converter.hpp"

Converter::Converter(){

}
Converter::Converter(std::string arg){
	// this->_type = whichType(arg);
}
Converter::Converter(Converter const& src){

}
Converter::~Converter(){

}
Converter& Converter::operator=(Converter const& rhs){
}

std::ostream& operator<<(std::ostream& o, Converter const& c){
	
}

Converter::TYPE Converter::whichType(std::string arg)
{
	if (arg.empty()) 
		return ERR;
	else if (foundChar(arg))
		return CHAR;
	else if (foundInt(arg))
		return INT;
	else if (foundDouble(arg))
		return DOUBLE;
	else if (foundFloat(arg))
		return FLOAT;
	else
		return ERR;
}
	// for (char const &c : arg) {
    //     if (std::isdigit(c) == 0) break;
    // } SCHREIBWEISE VERSTEHEN

void				Converter::convert_char(){

}
void				Converter::convert_int(){

}
void				Converter::convert_double(){

}
void				Converter::convert_float(){
	
}