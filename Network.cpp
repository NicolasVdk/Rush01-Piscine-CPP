#include "Network.hpp"

Network::Network(void) : _heigh(4)
{
	return ;
}

Network::~Network(void)
{
	return ;
}

int		Network::getHeigh(void) const
{
		return (this->_heigh);
}

void	Network::display(int y)
{
	void *oldp[1024];
	size_t oldlen = sizeof(struct ipstat), newlen = 0;
	void * newp = NULL;

	sysctlbyname("net.inet.ip.stats", oldp, &oldlen, newp, newlen);
	struct ipstat * g = (struct ipstat *) oldp;
	mvprintw(y, 0, "#---- Network ----#");
	mvprintw(y + 1, 0, " IP packets rcv:   %d\n", g->ips_total);
	mvprintw(y + 2, 0, " IP packets sent:  %d\n", g->ips_localout);
}

void	Network::displayMlx(int y)
{
	(void)y;
	/*
	void *oldp[1024];
	size_t oldlen = sizeof(struct ipstat), newlen = 0;
	void * newp = NULL;

	sysctlbyname("net.inet.ip.stats", oldp, &oldlen, newp, newlen);
	struct ipstat * g = (struct ipstat *) oldp;
	mvprintw(y, 0, "#---- Network ----#");
	mvprintw(y + 1, 0, " IP packets rcv:   %d\n", g->ips_total);
	mvprintw(y + 2, 0, " IP packets sent:  %d\n", g->ips_localout);
	*/
}
