#ifndef DATE_HPP
# define DATE_HPP

#include "IMonitorDisplay.hpp"
#include "IMonitorModule.hpp"

class Date: public IMonitorDisplay, public IMonitorModule
{
	public:
		Date(void);
		~Date(void);

		virtual int			getHeigh(void) const;

		virtual void		display(int y);


	private:
		int		_heigh;

		Date &		operator=(Date const & rhs);
		Date(Date const & src);
};

#endif
