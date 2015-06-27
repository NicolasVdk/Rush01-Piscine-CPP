#include "Network.hpp"

Network::Network(void) : _heigh(30)
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

int		Network::getHeigh(void) const
{
		return (this->_heigh);
}

Network&Network::operator=(Network const & rhs)
{
	return *this;
}
