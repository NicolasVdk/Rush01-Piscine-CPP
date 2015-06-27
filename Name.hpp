#ifndef NAME_HPP
# define NAME_HPP

#include <iostream>

class Name: public IMonitorDisplay, public IMonitorModule
{
	public:
		Name(void);
		Name(Name const & src);
		~Name(void);

		int			getHigh(void) const;

		Name &		operator=(Name const & rhs);

	private:
		int		_high;

};

#endif
