#include "Os_info.hpp"
#include <sys/sysctl.h>
#include <iostream>

Os_info::Os_info(void) : _heigh(1)
{
	size_t			len;
	char			str[1048];

	len = 1024;
	sysctlbyname("kern.ostype", str, &len, NULL, 0);
	this->_osType = str;
	len = 1024;
	sysctlbyname("kern.osrelease", str, &len, NULL, 0);
	this->_osRelease = str;
}

Os_info::~Os_info(void)
{
	return ;
}

int		Os_info::getHeigh(void) const
{
		return (this->_heigh);
}

void	Os_info::display(int y)
{
	mvprintw(y, 1, "Kernel version: %s", this->_osType.c_str());
	mvprintw(y + 1, 1, "%s", this->_osRelease.c_str());
	if (atoi(this->_osRelease.c_str()) == 14)
		mvprintw(y + 2, 1, "Product version: Yosemite");
	else if (atoi(this->_osRelease.c_str()) == 13)
		mvprintw(y + 2, 1, "Product version: Maverick");
}
