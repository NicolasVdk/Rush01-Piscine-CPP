#include "Name.hpp"

Name::Name(void) : _heigh(2)
{
	return ;
}


Name::~Name(void)
{
	return ;
}

void	Name::display( int y )
{
	char	hostname[1024];
	size_t	len = sizeof(hostname);
	struct 	passwd *pwd;

	if (!sysctlbyname("kern.hostname", &hostname, &len, NULL, 0))
		mvprintw(y, 0, "%s", hostname);
	pwd = getpwuid(geteuid());
	mvprintw(y + 1, 0, "%s", pwd->pw_name);
}

int		Name::getHeigh(void) const
{
		return (this->_heigh);
}