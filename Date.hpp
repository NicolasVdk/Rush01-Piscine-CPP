#ifndef DATE_HPP
# define DATE_HPP

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class Date: public IMonitorDisplay, public IMonitorModule
{
	public:
		Date(void);
		Date(Date const & src);
		~Date(void);

		int			getHeigh(void) const;

		void		displayDate(int y) const;

		Date &		operator=(Date const & rhs);

	private:
		int		_heigh;

};

#endif
