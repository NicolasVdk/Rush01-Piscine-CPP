#include "Network.hpp"

Network::Network(void) : _high(30)
{
	return ;
}

Network::Network(Network const & src)
{
	*this = src;
}

Network::~Network(void)
{
	return ;
}

int		Network::getHigh(void) const
{
		return (this->_high);
}

Network&Network::operator=(Network const & rhs)
{
	return *this;
}
