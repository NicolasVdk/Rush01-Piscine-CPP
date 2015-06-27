#ifndef CPU_HPP
# define CPU_HPP
# include <mach/mach_init.h>
# include <mach/mach_error.h>
# include <mach/mach_host.h>
# include <mach/vm_map.h>
# include <iostream>
# include <curses>

class CPU: public IMonitorDisplay, public IMonitorModule
{
	public:
		CPU(void);
		~CPU(void);

		int			getHigh(void) const;
		void		displayCPU(void);

	private:
		CPU(CPU const & src);
		CPU &		operator=(CPU const & rhs);
		int		_high;
		unsigned long long _previousIdleTicks;
		unsigned long long _previousUserTicks;
		unsigned long long _previousSystemTicks;
		unsigned long long _SystemTicks;
		unsigned long long _UserTicks;
		unsigned long long _IdleTicks;
		host_cpu_load_info_data_t _cpuinfo;
		mach_msg_type_number_t _count;

};

#endif
