#include "Name.hpp"

Name::Name(void) : _heigh(30)
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

int		Name::getHeigh(void) const
{
		return (this->_heigh);
}

Name&Name::operator=(Name const & rhs)
{
	return *this;
}
