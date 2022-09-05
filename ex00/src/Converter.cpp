# include "../incl/Converter.hpp"

Converter::Converter(): _overflow(false){

}
Converter::Converter(std::string arg): _overflow(false){
	// this->_type = whichType(arg);
}
Converter::Converter(Converter const& src): _overflow(src._overflow){

}
Converter::~Converter(){

}
Converter& Converter::operator=(Converter const& rhs){
	this->_overflow = rhs._overflow;
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
//der setzt immer nru den overflow auf true, fuer den type wo er gerade ist!
//also wenns kein char ist aber im char overflow war, dann geht er weiter zu int

bool				Converter::foundChar(std::string arg){
//bei char wird nicht nur decimal sondern auch character schreibweise verwendet
	if (arg[0] < 32 || arg[0] > 127)
		this->_overflow = true;
	else 
		this->_overflow = true;
//noch die schoenere schreibweise aber jetzt so, damit dus verstehst!
	//anstatt bool hier schon ImpossibleClass thrown?
	if (arg.length() == 1){
		//cast in char and store in _c
	//hier ist noch nicht klar obs darstellnar ist
	//dafuer muss man _overflow nochmal abfangen
		return true;
	}
}

bool				Converter::foundInt(std::string arg){

	char * pEnd; //point to the first character after the number
	long int li = strtol (arg, &pEnd, 10);
	if (li > std::numeric_limits<int>::max() || li < std::numeric_limits<int>::lowest())
		this->_overflow = true;
	else 
		this->_overflow = false;
	if (*pEnd == '\0'){
		//cast in char and store in _i
	//waere schoen aber so kann man nicht abchecken obs overflow hat
	//aber koennte man nicht gleich ne overflow exception thrown?
	//oder is das von fall zu fall unterschiedlich?
		return true;
	}
}
//ginge das hier mit try catch?
//das findet selber raus ob das ein reiner int ist
//done

bool				Converter::foundDouble(std::string arg){

	char * pEnd; //point to the first character after the number
	long double ld = strtold (arg, &pEnd, 10);
	if (ld > std::numeric_limits<double>::max() || ld < std::numeric_limits<double>::lowest())
		this->_overflow = true;
	else 
		this->_overflow = false;
	if (ld  == std::numeric_limits<double>::infinity() || -ld == std::numeric_limits<double>::infinity())
		this->_overflow = false;
	if (*pEnd == '\0'){

		return true;
	}
}
bool				Converter::foundFloat(std::string arg){
	char * pEnd; //point to the first character after the number
	long double lf = strtold (arg, &pEnd, 10);
	if (lf > std::numeric_limits<float>::max() || lf < std::numeric_limits<float>::lowest())
		this->_overflow = true;
	else 
		this->_overflow = false;
	if (ld  == std::numeric_limits<float>::infinity() || -ld == std::numeric_limits<float>::infinity())
		this->_overflow = false;
	if (!std::string(pEnd).compare("f")){

		return true;
	}
}
//koennte man noch improven mit nem priv attribute fuer arg
//ich wuerde heir das input handling machen, damit man danach einfach damit arbeiten kann 
//aka dann in den ConvertFunctions castet
//bis jetzt weiss amn obs ein c i d oder f ist und obs overflowed und obs inf -inf inff -inff ist

void				Converter::convert_char(){

	if (this->_overflow){
		std::cout << "INVALID INPUT: Input Value out of Range" << std::endl;
		return EXIT_FAILURE;
	}
	//ist dann automatisch nichts mehr darstellbar?
	//ja anscheinend
	this->_c = //cast arg zu c;
	this->_i = // cast arg zu int;
	this->_d = // cast arg zu double;
	this->_f = // cast zu float;
}
void				Converter::convert_int(){

	if (this->_overflow){
		std::cout << "INVALID INPUT: Input Value out of Range" << std::endl;
		return EXIT_FAILURE;
	}
	//ist dann automatisch nichts mehr darstellbar?

	this->_c = ;
	//passen die char regeln 32 127?
	this->_i = ;
	this->_d = // cast arg zu double;
	this->_f = // cast zu float;

}
void				Converter::convert_double(){

	if (this->_overflow){
		std::cout << "INVALID INPUT: Input Value out of Range" << std::endl;
		return EXIT_FAILURE;
	}
	//ist dann automatisch nichts mehr darstellbar?

	this->_c = ;
	//passen die char regeln 32 127?
	this->_i = ;
	//ist es uber int_max int_min?
	this->_d = // cast arg zu double;
	this->_f = // cast zu float;
}
void				Converter::convert_float(){

	if (this->_overflow){
		std::cout << "INVALID INPUT: Input Value out of Range" << std::endl;
		return EXIT_FAILURE;
	}
	//ist dann automatisch nichts mehr darstellbar?

	this->_c = ;
	//passen die char regeln 32 127?
	this->_i = ;
	//ist es uber int_max int_min?
	this->_d = ;// cast arg zu double;
	this->_f = ;// cast zu float;

}
//und dann noch nan inf -inf inff -inff handeln
//und wie schauen ob es uberhaupt castable ist??

std::ostream& operator<<(std::ostream& o, Converter const& c){
	std::cout << "char representation: " << c._c << "\n"
	<< "int representation: " << c._i << "\n"
	<< "double representation: " << c._d << "\n"
	<< "float representation: " << c._f << "\n"
}
//geht nicht so einfach
