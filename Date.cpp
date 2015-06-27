#include "Date.hpp"
#include <ctime>

Date::Date(void) : _heigh(30)
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

int		Date::getHeigh(void) const
{
		return (this->_heigh);
}

void	Date::display(int y)
{
	time_t	rawtime;
	struct	tm* timeinfo;
	char 	buffer[16];

	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime (buffer, 16, "%G%m%e_%H%M%S", timeinfo);

	mvprintw(y, 3, "%s", buffer);
}

Date&Date::operator=(Date const & rhs)
{
	return *this;
}
