
#include "bigint.hpp"



bigint ::bigint()
{
    this->str = "0";
}

bigint ::bigint (unsigned int num)
{
    std::stringstream string;
    string << num;
    this-> str = string.str();
}


bigint &bigint::operator+=(const bigint &other)
{
    int i =  this->str.length() - 1;
    int j = other.str.length()-1;
    int carry = 0;
    std::string res;
    while (i >= 0 || j >= 0 || carry )
    {
        int x = i >= 0 ? this->str[i] - '0' : 0;
        int y = j>=0 ? other.str[j] - '0' : 0;
        int sum  = x + y + carry ;
        carry = sum / 10;
        res.push_back((sum%10) + '0');
        i--;
        j--;
    }
    std::reverse(res.begin(), res.end());
    this->str = res;
    return *this;
}


bigint bigint::operator+(const bigint &other)const
{
    bigint res(*this);
    res+=other;
    return res;
}


bigint bigint::operator++(int)
{
    bigint res(1);
    bigint tmb(*this);

    *this += res;
    return tmb;
}


bigint &bigint::operator ++()
{
    bigint res(1);
    *this += res;
    return *this;

}





bigint bigint::operator<<(unsigned int amount)const
{
    bigint tem(*this);
    if (str != "0")
    {
        tem.str.append(amount, '0');
    }
    return tem ; 
}


bigint &bigint::operator<<=(unsigned int amount )
{
    if (this->str != "0")
    {
        this->str.append(amount, '0');
    }
    return *this;
}

bigint &bigint::operator>>=(const bigint &other)
{
    const unsigned int size  = str.size();
    const unsigned long amount  = std::atol(other.str.c_str());
    if (size >= amount)
        str.erase(size - amount);
    else 
        str  = "0";
    return *this ;
}




bool bigint::operator<(const bigint&other)const 
{
    return ((this->str.size()!= other.str.size())? this->str.size() < other.str.size() : this->str < other.str);
}


bool bigint :: operator > (const bigint &other)const
{
    return(!(*this < other));
}

bool bigint :: operator <=(const bigint &other )const 
{
    return (other > *this);
}

bool bigint::operator>=(const bigint &other)const
{
    return (other < *this);
}

bool bigint::operator ==(const bigint &other)const
{
    return (this->str==other.str);
}

bool bigint::operator!=(const bigint &other)const
{
    return (this->str!= other.str);
}


std::ostream & operator<<(std::ostream &os, const bigint &other)
{
    os<<other.getstr();
    return os;
}













// bigint::bigint ()
// {
//     this->str = "0";
// }


// bigint::bigint(unsigned int nm)
// {
//     std::stringstream s ;

//     s << nm;
//     this->str = s.str();

// }

// 25
// 67
// 92


// bigint &bigint::operator+=(const bigint &other)
// {
//     int i = str.size( ) - 1;
//     int j  = other.str.size() - 1  ;
//     int carry  = 0 ;
//     std::string res;
    
//     while (i >= 0 || j >= 0 || carry)
//     {
//         int x  =  i >= 0 ? str[i] - '0' : 0;
//         int y =   j >= 0 ? other.str[j] - '0' : 0;
//         int sum  = x + y + carry ;
//         carry  =  sum / 10 ;
//         str.push_back((sum % 10) + '0');
//         --i ;
//         --j ;
//     }
//     reverse(res.begin(), res.end()) ;
//     return (*this);
// }


// bigint &bigint::operator+=(const bigint &other)
// {
//     int i = this->str.size() - 1;
//     int j = other.str.size() - 1;
//     int carry  = 0 ;
//     std::string res;
//     while (i >= 0 || j >= 0 || carry)
//     {
//         int x =  i >= 0 ? this->str[i] - '0' : 0;
//         int y = j >= 0 ? other.str[j] - '0' : 0;
//         int sum = x + y + carry;
//         carry = sum / 10;
//         res.push_back((sum % 10) + '0');
//         --i;
//         --j;
//     }
//     reverse(res.begin(), res.end());
//     this->str = res;
//     return (*this);
// }



// bigint bigint::operator+(const bigint &other)const
// {
//     bigint  res(*this);
//     res += other;
//     return res;
// }


// bigint &bigint::operator++()
// {
//     bigint d(1);
//     *this += d;
//     return *this ;
// }

// bigint bigint::operator++(int)
// {
//     bigint tem(*this);
//     bigint d(1);
//     *this += d;
//     return tem;
// }

// bigint &bigint::operator<<=(unsigned int amount )
// {
//     if (str != "0")
//         str.append(amount,'0');
//     return *this;
// }

// bigint bigint::operator<<(unsigned int amount) const 
// {
//     bigint tem(*this);
//     tem <<= amount;
//     return tem;
// }

// bigint &bigint::operator>>=(const bigint &other)
// {
//     const unsigned int size = str.size();
//     const unsigned long amount =  std::atol(other.str.c_str());
//     size >= amount ? str.erase(size - amount) : str = "0";
//     return *this ;
// }

// bool bigint::operator<(const bigint &other)const
// {
//     if (str.size() != other.str.size())
//     {
//         return str.size() < other.str.size();
//     }

//     return str < other.str;
// }

    // bool operator>(const bigint &other)const;//
    // bool operator<=(const bigint &other)const;//
    // bool operator>=(const bigint &other)const;
    // bool operator==(const bigint &other)const;
    // bool operator!=(const bigint &other)const;


// bool bigint::operator>(const bigint &other)const { return (other < *this);}

// bool bigint::operator<=(const bigint &other)const {return !(*this>other);}

// bool bigint :: operator>= (const bigint &other)const {return !(*this < other);}

// bool bigint :: operator == (const bigint &other) const {return (str ==  other.str);}

// bool bigint :: operator != (const bigint &other)const {return (str != other.str) ;}

// std::ostream	&operator<<(std::ostream &out, const bigint &other)
// {
// 	out << other.getBig();
// 	return (out);
// }
