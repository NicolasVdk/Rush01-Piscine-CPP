#ifndef CPU_HPP
# define CPU_HPP

#include <iostream>

class CPU: public IMonitorDisplay, public IMonitorModule
{
	public:
		CPU(void);
		CPU(CPU const & src);
		~CPU(void);

		int			getHigh(void) const;

		CPU &		operator=(CPU const & rhs);

	private:
		int		_high;

};

#endif
