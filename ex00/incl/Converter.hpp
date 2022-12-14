# include <limits>
# include <iostream>
# include <string>
# include <cstdlib>
# include <iomanip>
# include <sstream>



class Converter{

	public:
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
		void				convert_char(std::string arg);
		void				convert_int(std::string arg);
		void				convert_double(std::string arg);
		void				convert_float(std::string arg);
		bool				foundChar(std::string arg);
		bool				foundInt(std::string arg);
		bool				foundDouble(std::string arg);
		bool				foundFloat(std::string arg);

		char	_c;
		int		_i;
		double	_d;
		float	_f;
		bool _inf;
		bool _inff;
		std::string _input;

	private:

		bool _overflow;

};

std::ostream& operator<<(std::ostream& o, Converter const& c);
//could've used inbuilt cast functions?