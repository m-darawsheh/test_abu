#pragma once

# include <iostream>

class	vect2
{
	public:
		vect2(int x = 0, int y = 0) : x(x), y(y) {};
		vect2(const vect2 &other) : x(other.x), y(other.y) {};
		
		vect2	&operator=(const vect2 &other);

		// Accesses
		int	operator[](int index) const;
		int	&operator[](int index);

		// Increments & Decrements
		vect2	&operator++();		// ++x
		vect2	operator++(int);	// x++
		vect2	&operator--();		// --x
		vect2	operator--(int);	// x--

		// Maths
		vect2	operator+(const vect2 &other) const;
		vect2	&operator+=(const vect2 &other);

		vect2	operator-(const vect2 &other) const;
		vect2	&operator-=(const vect2 &other);

		vect2	operator*(int scalar) const;
		vect2	&operator*=(int scalar);

		// Unary Minus
		vect2	operator-() const;

		// Comparisons
		bool	operator==(const vect2 &other) const;
		bool	operator!=(const vect2 &other) const;

	private:
		int	x;
		int	y;
};

vect2	operator*(int scalar, const vect2 &other);

std::ostream	&operator<<(std::ostream &out, const vect2 &other);
