#ifndef OS_INFO_HPP
# define OS_INFO_HPP

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class Os_info: public IMonitorDisplay, public IMonitorModule
{
	public:
		Os_info(void);
		Os_info(Os_info const & src);
		~Os_info(void);

		int			getHeigh(void) const;

		Os_info &		operator=(Os_info const & rhs);

	private:
		int		_heigh;

};

#endif
