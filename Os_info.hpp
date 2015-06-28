#ifndef OS_INFO_HPP
# define OS_INFO_HPP

#include "IMonitorModule.hpp"
#include <string>

class Os_info: public IMonitorModule
{
	public:
		Os_info(void);
		virtual ~Os_info(void);

		virtual int			getHeigh(void) const;

		virtual void		display(int y);

	private:
		int			_heigh;
		std::string	_osRelease;
		std::string	_osType;
		std::string _osName;

		Os_info(Os_info const & src);

		Os_info &		operator=(Os_info const & rhs);

};

#endif
