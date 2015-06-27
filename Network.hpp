#ifndef NETWORK_HPP
# define NETWORK_HPP

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class Network: public IMonitorDisplay, public IMonitorModule
{
	public:
		Network(void);
		Network(Network const & src);
		~Network(void);

		int			getHeigh(void) const;

		Network &		operator=(Network const & rhs);

	private:
		int		_heigh;

};

#endif
