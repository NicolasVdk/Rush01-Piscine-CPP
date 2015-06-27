#ifndef RAM_HPP
# define RAM_HPP

# include "IMonitorModule.hpp"
# include <mach/vm_statistics.h>
# include <mach/mach_types.h>
# include <mach/mach_init.h>
# include <mach/mach_host.h>
# include <stdio.h>
# include <stdint.h>
# include <sys/types.h>
# include <sys/sysctl.h>

class RAM : public IMonitorModule
{
	public:
		RAM();
		~RAM();
		virtual int		getHeigh(void) const;
		virtual void	display(int y);

	private:

		uint64_t	get_mem(void) const;
		RAM &		operator=(RAM const & rhs);
		RAM(RAM const & src);
		int		_heigh;
};

#endif
