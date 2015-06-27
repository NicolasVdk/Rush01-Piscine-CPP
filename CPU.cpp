#include "CPU.hpp"

CPU::CPU(void) : _high(30)
{
	return ;
}

CPU::CPU(CPU const & src)
{
	*this = src;
}

CPU::~CPU(void)
{
	return ;
}

int		CPU::getHigh(void) const
{
	return (this->_high);
}

CPU&CPU::operator=(CPU const & rhs)
{
	return *this;
}
