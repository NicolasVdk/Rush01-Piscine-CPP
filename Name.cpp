#include "Name.hpp"

Name::Name(void) : _high(30)
{
	return ;
}

Name::Name(Name const & src)
{
	*this = src;
}

Name::~Name(void)
{
	return ;
}

int		Name::getHigh(void) const
{
		return (this->_high);
}

Name&Name::operator=(Name const & rhs)
{
	return *this;
}
