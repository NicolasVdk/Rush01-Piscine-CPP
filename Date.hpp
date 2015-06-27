#ifndef DATE_HPP
# define DATE_HPP

#include <iostream>

class Date: public IMonitorDisplay, public IMonitorModule
{
	public:
		Date(void);
		Date(Date const & src);
		~Date(void);

		int			getHigh(void) const;

		Date &		operator=(Date const & rhs);

	private:
		int		_high;

};

#endif
