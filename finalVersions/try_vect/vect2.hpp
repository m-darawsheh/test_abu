
#include <iostream>



// int	vect2::operator[](int index) const { return index == 0 ? x : y; }
// int	&vect2::operator[](int index) { return index == 0 ? x : y; }

		// Increments & Decrements
		// vect2	&operator++();		// ++x
		// vect2	operator++(int);	// x++
		// vect2	&operator--();		// --x
		// vect2	operator--(int);	// x--


    // vect2	operator+(const vect2 &other) const;
	// vect2	&operator+=(const vect2 &other);
	// vect2	operator-(const vect2 &other) const;
	// vect2	&operator-=(const vect2 &other);
	// vect2	operator*(int scalar) const;
	// vect2	&operator*=(int scalar);


class vect2
{
    private:
    int x;
    int y;
    public:
    
    vect2(int x, int y):x(x),y(y){};
    vect2(const vect2 &other):x(other.x), y(other.y){};
    
    vect2 &operator=(const vect2 &other);

    int operator[](int index)const {return index==0?x:y;};
    int &operator[](int index){return index == 0 ? x : y;};

    vect2 operator++(int);
    vect2 &operator++();
    vect2 &operator--();
    vect2 operator--(int);

    vect2 operator+(const vect2 &other)const;


};