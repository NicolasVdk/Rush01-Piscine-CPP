#include "Date.hpp"

Date::Date(void) : _high(30)
{
	return ;
}

Date::Date(Date const & src)
{
	*this = src;
}

Date::~Date(void)
{
	return ;
}

int		Date::getHigh(void) const
{
		return (this->_high);
}

Date&Date::operator=(Date const & rhs)
{
	return *this;
}
