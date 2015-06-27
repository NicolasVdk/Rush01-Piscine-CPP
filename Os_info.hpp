#ifndef OS_INFO_HPP
# define OS_INFO_HPP

#include <iostream>

class Os_info: public IMonitorDisplay, public IMonitorModule
{
	public:
		Os_info(void);
		Os_info(Os_info const & src);
		~Os_info(void);

		int			getHigh(void) const;

		Os_info &		operator=(Os_info const & rhs);

	private:
		int		_high;

};

#endif
