# include <limits>
# include <iostream>
# include <string>
# include <cstdlib>
#include <iomanip>
#include <sstream>



class Converter{

	public:

		class NonDisplayable: public std::exception{
			const char* what() const throw();	
		};
		class Impossible: public std::exception{
			const char* what() const throw();
		};

		Converter();
		Converter(std::string arg);
		Converter(Converter const& src);
		Converter&	operator=(Converter const& rhs);
		~Converter();

		enum TYPE{
			PSEUDO,
			CHAR,
			INT,
			DOUBLE,
			FLOAT,
			ERR,
		};
		Converter::TYPE		whichType(std::string arg);
		void					convert_pseudo(std::string arg);
		void					convert_char(std::string arg);
		void					convert_int(std::string arg);
		void					convert_double(std::string arg);
		void					convert_float(std::string arg);
		//oder hier den ruckgabe wert noch aendern, dass die das direkt in den << eingeben
		bool				foundPseudo(std::string arg);
		bool				foundChar(std::string arg);
		bool				foundInt(std::string arg);
		bool				foundDouble(std::string arg);
		bool				foundFloat(std::string arg);

		char	_c;
		int		_i;
		double	_d;
		float	_f;

	private:

		bool _overflow;
		bool _inf;
		bool _inff;

};

std::ostream& operator<<(std::ostream& o, Converter const& c);
//use const everywhere...
//in den Videos gabs hier diese inbuilt cast functions...