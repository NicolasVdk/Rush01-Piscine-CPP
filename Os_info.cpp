#include "Os_info.hpp"

Os_info::Os_info(void): _heigh(30)
{
	return ;
}

Os_info::Os_info(Os_info const & src)
{
	*this = src;
}

Os_info::~Os_info(void)
{
	return ;
}

int		Os_info::getHeigh(void) const
{
		return (this->_heigh);
}

Os_info & Os_info::operator=(Os_info const & rhs)
{
	return *this;
}
