#ifndef NAME_HPP
# define NAME_HPP
# include <sys/sysctl.h>
# include <sys/types.h>
# include <pwd.h>
# include <unistd.h>
#include "IMonitorModule.hpp"

class Name: public IMonitorModule
{
	public:
		Name(void);
		~Name(void);

		virtual int			getHeigh(void) const;
		virtual void		display( int y );
		virtual void		displayMlx( int y );

	private:
		Name(Name const & src);
		Name &		operator=(Name const & rhs);
		int		_heigh;

};

#endif
