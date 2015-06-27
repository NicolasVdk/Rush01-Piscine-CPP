#include "Date.hpp"
#include <ctime>

Date::Date(void) : _heigh(3)
{
	return ;
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
	char 	buffer[25];

	time (&rawtime);
	timeinfo = localtime (&rawtime);
	strftime (buffer, 25, "%c", timeinfo);
	mvprintw(y, 0, "#------ Date -----#");
	mvprintw(y + 1, 0, " %s", buffer);
}
