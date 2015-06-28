#include "Os_info.hpp"
#include <sys/sysctl.h>
#include <iostream>
#include <fstream>
#include <algorithm>

Os_info::Os_info(void) : _heigh(6)
{
	size_t			len;
	char			str[1024];

	len = sizeof(str);
	sysctlbyname("kern.ostype", str, &len, NULL, 0);
	this->_osType = str;
	len = sizeof(str);
	sysctlbyname("kern.osrelease", str, &len, NULL, 0);
	this->_osRelease = str;
	std::ifstream	ifs("/System/Library/CoreServices/SystemVersion.plist");
	std::string		buffer;
	while (std::getline(ifs, buffer))
	{
		if (buffer.find("ProductVersion") != std::string::npos)
		{
			if (std::getline(ifs, buffer))
				this->_osName = buffer.substr(9, 7);
			else
				buffer = "No version founded";
		}
	}
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
	mvprintw(y, 0, "#---- OS Info ----#");
	mvprintw(y + 1, 1, "Kernel name:     %s", this->_osType.c_str());
	mvprintw(y + 2, 1, "Kernel version:  %s", this->_osRelease.c_str());
	if (atoi(this->_osRelease.c_str()) == 14)
		mvprintw(y + 3, 1, "Product name:    Yosemite");
	else if (atoi(this->_osRelease.c_str()) == 13)
		mvprintw(y + 3, 1, "Product name:    Maverick");
	mvprintw(y + 4, 1, "Product version: %s", this->_osName.c_str());
}

