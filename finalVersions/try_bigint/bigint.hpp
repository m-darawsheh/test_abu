
#include <iostream>
#include  <string>
#include <algorithm>
#include <sstream>

		// bigint	&operator++();		// ++x
		// bigint	operator++(int);	// x++

class bigint
{
    public :
    bigint ();
    bigint (unsigned int num);
    bigint (const bigint &other):str(other.str){};
    std::string getstr()const{return str;};

    bigint operator +(const bigint &other)const;
    bigint &operator +=(const bigint &other);

    bigint &operator++();
    bigint operator++(int);

    bigint operator<<(unsigned int amount)const;
    bigint &operator<<=(unsigned int amount);
    bigint &operator>>=(const bigint &other);



    bool operator<(const bigint &other)const;
    bool operator <= (const bigint &other )const ;
    bool operator > (const bigint &other) const ;
    bool operator >= (const bigint &other)const ;
    bool operator == (const bigint &other)const ;
    bool operator != (const bigint &other)const ;

    private : 
    std::string str;
};




std::ostream &operator <<(std::ostream &os, const bigint &other);















































// class bigint
// {
//     private:
//     std::string str;

//     public:
//     bigint ();
//     bigint (unsigned int nm);
//     bigint (const bigint &other): str(other.str) {};

//     std::string getBig() const {return str;};

//     // addtion
//     bigint operator+(const bigint &other)const ;
//     bigint &operator+=(const bigint &other);

//     // increments
//     bigint &operator++();  //++x
//     bigint operator++(int);  //x++

//     // shift 
//     bigint operator<<(unsigned int amount) const ;
//     bigint &operator<<=(unsigned int amount );
//     bigint &operator>>=(const bigint &other);

//     // comparisons
//     bool operator<(const bigint &other)const;
//     bool operator>(const bigint &other)const;
//     bool operator<=(const bigint &other)const;
//     bool operator>=(const bigint &other)const;
//     bool operator==(const bigint &other)const;
//     bool operator!=(const bigint &other)const;

// };

// std::ostream	&operator<<(std::ostream &out, const bigint &other);























