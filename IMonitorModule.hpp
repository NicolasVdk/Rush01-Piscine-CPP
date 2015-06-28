#ifndef IMONITORMODULE_HPP
# define IMONITORMODULE_HPP

# include <ncurses.h>

class IMonitorModule
{
	public:
		virtual void display( int y ) = 0;
		virtual int getHeigh( void ) const = 0;	
};

#endif
