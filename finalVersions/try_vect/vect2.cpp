#include "vect2.hpp"

vect2 &vect2::operator++()
{
    ++x;
    ++y;
    return *this;
}

vect2 vect2::operator++(int)
{
    vect2 temp(*this);
    this->x++;
    this->y++;
    return temp;
}

vect2 &vect2::operator= (const vect2 &other)
{
    this->x = other.x;
    this->y = other.y;
    return *this;
}


vect2 vect2::operator--(int)
{
    vect2 tem (*this); 
    this-> x++;
    this-> y++;
    return tem;
}

vect2 &vect2::operator--()
{
    ++x;
    ++y;
    return *this;
}


vect2  vect2::operator+(const vect2 &other)const
{
    int tot_x;
    int tot_y;

    tot_x = this->x + other.x;
    tot_y = this->y + other.y;
    vect2 (tot_x , tot_y);
    return 
}