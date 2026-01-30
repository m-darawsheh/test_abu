#include "bigint.hpp"
bigint::bigint()
{
	this->str = "0";
}

bigint::bigint(unsigned int num)
{
	std::stringstream ss;
	ss << num;
	this->str = ss.str();
	// std::cout << "str: " << str << std::endl;
}

bigint	&bigint::operator+=(const bigint &other)
{
	// 40 += 600
	int	carry = 0;
	int	i = str.size() - 1;
	// i = 1
	int	j = other.str.size() - 1;
	// j = 2
	std::string	result;

	while (i >= 0 || j >= 0 || carry)
	{
		int	x = i >= 0 ? str[i] - '0' : 0;
		int	y = j >= 0 ? other.str[j] - '0' : 0;
		int	sum = x + y + carry;
		carry = sum / 10;
		result.push_back((sum % 10) + '0');
		--i;
		--j;
	}

	std::reverse(result.begin(), result.end());
	str = result;

	return (*this);
}

bigint	bigint::operator+(const bigint &other) const
{
	bigint	result(*this);
	result += other;
	return (result);
}

bigint	&bigint::operator++()
{
	bigint	dummy(1);
	*this += dummy;
	return (*this);
}

bigint	bigint::operator++(int)
{
	bigint	dummy(1);
	bigint	tmp(*this);
	*this += dummy;
	return (tmp);
}

bigint	&bigint::operator<<=(unsigned int amount)
{
	if (str != "0")
		str.append(amount, '0');
	return (*this);
}

bigint	bigint::operator<<(unsigned int amount) const
{
	bigint	result(*this);
	result <<= amount;
	return (result);
}

bigint	&bigint::operator>>=(const bigint &other)
{
	const unsigned int	size = str.size();//this is to get the size of the string
	const unsigned long	amount = std::atol(other.str.c_str());//this is to convert string to unsigned long

	size >= amount
		? str.erase(size - amount)
		: str = "0";

	return (*this);
}

bool	bigint::operator<(const bigint &other) const
{
	return (str.size() != other.str.size()) ? str.size() < other.str.size() : str < other.str;
}

bool	bigint::operator>(const bigint &other) const { return (other < *this); }
bool	bigint::operator<=(const bigint &other) const { return !(*this > other); }
bool	bigint::operator>=(const bigint &other) const { return !(*this < other); }
bool	bigint::operator==(const bigint &other) const { return (str == other.str); }
bool	bigint::operator!=(const bigint &other) const { return (str != other.str); }

std::ostream	&operator<<(std::ostream &out, const bigint &other)
{
	out << other.getBig();
	return (out);
}
