#include "CPU.hpp"
#include <iostream>

CPU::CPU( void ) : _heigh(6)
{
	size_t	len = sizeof(this->_CPU);
	sysctlbyname("machdep.cpu.brand_string", &this->_CPU, &len, NULL, 0);
	sysctlbyname("hw.ncpu", &this->_nCPU, &len, NULL, 0);
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
		mvprintw(y, 0, "#------ CPU ------#");
		mvprintw(y + 1, 1, "%s", this->_CPU);
		mvprintw(y + 2, 1, "User : %.2f%%", static_cast<float>(this->_UserTicks) / this->_nCPU);
		mvprintw(y + 3, 1, "Sys  : %.2f%%", static_cast<float>(this->_SystemTicks) / this->_nCPU);
		mvprintw(y + 4, 1, "Idle : %.2f%%", static_cast<float>(this->_IdleTicks) / this->_nCPU);
	}
}

CPU::~CPU(void)
{
	return ;
}

int		CPU::getHeigh(void) const
{
	return (this->_heigh);
}
