#include "CPU.hpp"

CPU::CPU( void ) : _high(10)
{
	this->_SystemTicks = 0;
	this->_UserTicks = 0;
	this->_IdleTicks = 0;
	this->_previousIdleTicks = 0;
	this->_previousUserTicks = 0;
	this->_previousSystemTicks = 0;
	this->_count = HOST_CPU_LOAD_INFO_COUNT;
	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, reinterpret_cast<host_info_t>(&this->_cpuinfo), &this->_count) == KERN_SUCCESS)
	{
		this->_previousUserTicks = this->_cpuinfo.cpu_ticks[0];
		this->_previousSystemTicks = this->_cpuinfo.cpu_ticks[1];
		this->_previousIdleTicks = this->_cpuinfo.cpu_ticks[2];
	}
}

void	CPU::display( int y )
{
	if (host_statistics(mach_host_self(), HOST_CPU_LOAD_INFO, reinterpret_cast<host_info_t>(&this->_cpuinfo), &this->_count) == KERN_SUCCESS)
	{
		this->_UserTicks = this->_cpuinfo.cpu_ticks[0] - this->_previousUserTicks;
		this->_SystemTicks = this->_cpuinfo.cpu_ticks[1] - this->_previousSystemTicks;
		this->_IdleTicks = this->_cpuinfo.cpu_ticks[2] - this->_previousIdleTicks;
		this->_previousUserTicks = this->_cpuinfo.cpu_ticks[0];
		this->_previousSystemTicks = this->_cpuinfo.cpu_ticks[1];
		this->_previousIdleTicks = this->_cpuinfo.cpu_ticks[2];
		mvprintw(y + 0, 0, "User : %.2f%%", static_cast<float>(this->_UserTicks) / 4);
		mvprintw(y + 1, 0, "Sys  : %.2f%%", static_cast<float>(this->_SystemTicks) / 4);
		mvprintw(y + 2, 0, "Idle : %.2f%%", static_cast<float>(this->_IdleTicks) / 4);
	}
}

CPU::~CPU(void)
{
	return ;
}

int		CPU::getHeigh(void) const
{
	return (this->_high);
}
