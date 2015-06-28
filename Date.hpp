#ifndef DATE_HPP
# define DATE_HPP

#include "IMonitorModule.hpp"

class Date: public IMonitorModule
{
	public:
		Date(void);
		virtual ~Date(void);

		virtual int			getHeigh(void) const;

		virtual void		display(int y);


	private:
		int		_heigh;

		Date &		operator=(Date const & rhs);
		Date(Date const & src);
};

#endif
