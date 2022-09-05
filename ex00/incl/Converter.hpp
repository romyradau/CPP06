# include <limits>
# include <iostream>
# include <string>


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
			CHAR,
			INT,
			DOUBLE,
			FLOAT,
			ERR,
		};
		Converter::TYPE		whichType(std::string arg);
		void				convert_char();
		void				convert_int();
		void				convert_double();
		void				convert_float();
		//oder hier den ruckgabe wert noch aendern, dass die das direkt in den << eingeben
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

};

std::ostream& operator<<(std::ostream& o, Converter const& c);
//use const everywhere...
//in den Videos gabs hier diese inbuilt cast functions...