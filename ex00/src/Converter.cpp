# include "../incl/Converter.hpp"

Converter::Converter(): _overflow(false), _inf(false), _inff(false){

}
Converter::Converter(std::string arg): _overflow(false), _inf(false), _inff(false){
}

Converter::Converter(Converter const& src): _overflow(src._overflow), _inf(src._inf), _inff(src._inff){

}
Converter::~Converter(){

}
Converter& Converter::operator=(Converter const& rhs){

	this->_overflow = rhs._overflow;
	return *this;
}


Converter::TYPE Converter::whichType(std::string arg)
{
	if (arg.empty()) 
		return ERR;
	else if (foundPseudo(arg))
		return PSEUDO;
	else if (foundInt(arg))
		return INT;
	else if (foundChar(arg))
		return CHAR;
	else if (foundDouble(arg))
		return DOUBLE;
	else if (foundFloat(arg))
		return FLOAT;
	else
		return ERR;
}

/*********************Finders******************/


bool				Converter::foundPseudo(std::string arg){
	std::cout << "foundPseudo" << std::endl;
	return (std::string(arg).compare("nan") || std::string(arg).compare("nanf") 
	|| std::string(arg).compare("-inf") || std::string(arg).compare("inf")
	|| std::string(arg).compare("-inff") || std::string(arg).compare("inff"));
}

bool				Converter::foundChar(std::string arg){
	std::cout << "foundChar" << std::endl;

	this->_overflow = (arg[0] < 32 || arg[0] > 127);
	return (arg.length() == 1);
}

bool				Converter::foundInt(std::string arg){
	std::cout << "foundInt" << std::endl;

	char * pEnd;
	long int li = strtol (arg.c_str(), &pEnd, 10);
	this->_overflow = (li > std::numeric_limits<int>::max() || li < std::numeric_limits<int>::lowest());
	return (*pEnd == '\0');
}


bool				Converter::foundDouble(std::string arg){
	std::cout << "foundDouble" << std::endl;

	char * pEnd;
	long double ld = strtold (arg.c_str(), &pEnd);
	this->_overflow = (ld > std::numeric_limits<double>::max() || ld < std::numeric_limits<double>::lowest());
	this->_inf =  (ld  == std::numeric_limits<double>::infinity() || -ld == std::numeric_limits<double>::infinity());
	return (*pEnd == '\0');
}

bool				Converter::foundFloat(std::string arg){
	std::cout << "foundFloat" << std::endl;
	char * pEnd;
	long double lf = strtold (arg.c_str(), &pEnd);
	this->_overflow =(lf > std::numeric_limits<float>::max() || lf < std::numeric_limits<float>::lowest());
	this->_inff = (lf  == std::numeric_limits<float>::infinity() || -lf == std::numeric_limits<float>::infinity());
	return (!std::string(pEnd).compare("f"));
}

/*********************Converters******************/

void			Converter::convert_pseudo(std::string arg){
	std::cout << "char representation: impossible" << "\n"
	<< "int representation: impossible" << "\n"
	<< "double representation: " << std::fixed << std::setprecision(2) << c._d << "\n"
	<< "float representation: " << c._f << "f" << "\n";
	return o;
}

void			Converter::convert_char(std::string arg){

	std::cout << "foundChar" << std::endl;
	if (this->_overflow)
		throw Impossible();
	this->_c = static_cast<char>(arg[0]);//cast arg zu c;
	this->_i = static_cast<int>(this->_c);// cast arg zu int;
	this->_d = static_cast<double>(this->_c);// cast arg zu double;
	this->_f = static_cast<float>(this->_c);// cast zu float;
}

void				Converter::convert_int(std::string arg){

	std::cout << "foundInt" << std::endl;
	if (this->_overflow)
		throw Impossible();
	int new_arg = stoi(arg, NULL);
	this->_i = static_cast<int>(new_arg);

	if (this->_i < 32 || this->_i > 127)
		this->_c = static_cast<char>(this->_i);
	this->_d = static_cast<double>(this->_i);

	this->_f = static_cast<float>(this->_i);
}

void				Converter::convert_double(std::string arg){

	std::cout << "foundDouble" << std::endl;
	if (this->_overflow)
		throw Impossible();
	double new_arg = stod(arg, NULL);
	this->_d = static_cast<double>(new_arg);

	if (this->_d < 32 || this->_d > 127)
		this->_c = static_cast<char>(this->_d);

	if (this->_d < std::numeric_limits<int>::max() || this->_d > std::numeric_limits<int>::lowest())
		this->_i = static_cast<int>(this->_d);

	this->_f = static_cast<float>(this->_d);
}

void				Converter::convert_float(std::string arg){

	std::cout << "foundFloat" << std::endl;
	if (this->_overflow)
		throw Impossible();
	float new_arg = stof(arg, NULL);
	this->_f = static_cast<float>(new_arg);

	if (this->_f > 32 || this->_f < 127)
		this->_c = static_cast<char>(this->_f);

	if (this->_f < std::numeric_limits<int>::max() || this->_f > std::numeric_limits<int>::lowest())
		this->_i = static_cast<int>(this->_f);

	this->_d = static_cast<double>(this->_f);

}
//und dann noch !!nan inf -inf inff -inff handeln!!
//und wie schauen ob es uberhaupt castable ist??


const char* Converter::NonDisplayable::what() const throw(){
	
	return ("nan");
}


const char* Converter::Impossible::what() const throw(){
	
	return ("impossible");
}

std::ostream& operator<<(std::ostream& o, Converter const& c){

	o << "char representation: " << c._c << "\n"
	<< "int representation: " << c._i << "\n"
	<< "double representation: " << std::fixed << std::setprecision(2) << c._d << "\n"
	<< "float representation: " << c._f << "f" << "\n";
	return o;
}
//hier mit ifs arbeiten

