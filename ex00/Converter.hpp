# include <limits>
# include <iostream>


class Converter{

	public:
		Converter();
		Converter(Converter const& src);
		Converter&	operator=(Converter const& rhs);
		~Converter();

		void	convert_char();
		void	convert_int();
		void	convert_double();
		void	convert_float();

	private:
		enum{
			CHAR,
			INT,
			DOUBLE,
			FLOAT,
			ERR,
		}
};

std::ostream& operator<<(std::ostream& o, Converter const& c);