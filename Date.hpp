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

		virtual int			getHeigh(void) const;

		virtual void		display(int y);

		Date &		operator=(Date const & rhs);

	private:
		int		_heigh;

};

#endif
