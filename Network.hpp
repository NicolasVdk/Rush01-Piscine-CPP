#ifndef NETWORK_HPP
# define NETWORK_HPP

#include <iostream>

class Network: public IMonitorDisplay, public IMonitorModule
{
	public:
		Network(void);
		Network(Network const & src);
		~Network(void);

		int			getHigh(void) const;

		Network &		operator=(Network const & rhs);

	private:
		int		_high;

};

#endif
