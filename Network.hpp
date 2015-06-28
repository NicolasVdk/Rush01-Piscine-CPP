#ifndef NETWORK_HPP
# define NETWORK_HPP

# include "IMonitorModule.hpp"

# include <sys/types.h>
# include <sys/sysctl.h>
# include <sys/socketvar.h>
# include <netinet/ip.h>
# include <netinet/ip_var.h>

class Network: public IMonitorModule
{
	public:
		Network(void);
		virtual ~Network(void);

		virtual int		getHeigh(void) const;
		virtual void	display(int y);


	private:
		int		_heigh;

		Network &		operator=(Network const & rhs);
		Network(Network const & src);
};

#endif
