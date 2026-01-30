#pragma once

# include <iostream>
# include <algorithm>
#include <string>
#include <sstream>

class	bigint
{
	public:
		bigint();
		bigint(unsigned int nbr);
		bigint(const bigint &other) : str(other.str) {};

		std::string	getBig() const { return (str); };

		// Additions
		bigint	operator+(const bigint &other) const;
		bigint	&operator+=(const bigint &other);

		// Increments
		bigint	&operator++();		// ++x
		bigint	operator++(int);	// x++

		// Shifts
		bigint	operator<<(unsigned int amount) const;
		bigint	&operator<<=(unsigned int amount);
		bigint	&operator>>=(const bigint &other);

		// Comparisons
		bool	operator<(const bigint &other) const;
		bool	operator>(const bigint &other) const;
		bool	operator<=(const bigint &other) const;
		bool	operator>=(const bigint &other) const;
		bool	operator==(const bigint &other) const;
		bool	operator!=(const bigint &other) const;

	private:
		std::string	str;
};

// Ostream
std::ostream	&operator<<(std::ostream &out, const bigint &other);
