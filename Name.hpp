#ifndef NAME_HPP
# define NAME_HPP

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class Name: public IMonitorDisplay, public IMonitorModule
{
	public:
		Name(void);
		Name(Name const & src);
		~Name(void);

		int			getHeigh(void) const;

		Name &		operator=(Name const & rhs);

	private:
		int		_heigh;

};

#endif
