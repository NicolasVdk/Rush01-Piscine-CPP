#ifndef NAME_HPP
# define NAME_HPP
# include <sys/sysctl.h>
# include <sys/types.h>
# include <pwd.h>
# include <unistd.h>
# include "IMonitorDisplay.hpp"
//#include "IMonitorModule.hpp"

class Name: public IMonitorDisplay//, public IMonitorModule
{
	public:
		Name(void);
		~Name(void);

		int			getHeigh(void) const;
		void		display( int y );

	private:
		Name(Name const & src);
		Name &		operator=(Name const & rhs);
		int		_heigh;

};

#endif
