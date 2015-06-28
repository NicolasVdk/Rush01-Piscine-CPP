#include "Name.hpp"

Name::Name(void) : _heigh(4)
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

	mvprintw(y, 0, "#---- Hostname ---#");
	if (!sysctlbyname("kern.hostname", &hostname, &len, NULL, 0))
		mvprintw(y + 1, 1, "%s", hostname);
	pwd = getpwuid(geteuid());
	mvprintw(y + 2, 1, "%s", pwd->pw_name);
}

void	Name::displayMlx( int y )
{
	/*char	hostname[1024];
	size_t	len = sizeof(hostname);
	struct 	passwd *pwd;

	mvprintw(y, 0, "#---- Hostname ---#");
	if (!sysctlbyname("kern.hostname", &hostname, &len, NULL, 0))
		mvprintw(y + 1, 1, "%s", hostname);
	pwd = getpwuid(geteuid());
	mvprintw(y + 2, 1, "%s", pwd->pw_name);
	*/
}

int		Name::getHeigh(void) const
{
		return (this->_heigh);
}
