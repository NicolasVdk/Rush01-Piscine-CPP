#include "Os_info.hpp"

Os_info::Os_info(void): _high(30)
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

int		Os_info::getHigh(void) const
{
		return (this->_high);
}

Os_info & Os_info::operator=(Os_info const & rhs)
{
	return *this;
}
