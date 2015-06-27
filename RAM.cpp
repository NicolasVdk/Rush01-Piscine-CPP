#include "RAM.hpp"

RAM::RAM( void ) : _heigh(3)
{

}

RAM::~RAM( void )
{

}

uint64_t	RAM::get_mem(void) const
{
    uint64_t mem = 0;
    size_t size = sizeof(mem);

    if (sysctlbyname("hw.memsize", &mem, &size, NULL, 0) < 0)
        perror("sysctl");
    return (mem);
}

void	RAM::display(int y)
{
	vm_size_t page_size;
	mach_port_t mach_port;
	mach_msg_type_number_t count;
	vm_statistics64_data_t vm_stats;

	mach_port = mach_host_self();
	count = sizeof(vm_stats) / sizeof(natural_t);
	if (KERN_SUCCESS == host_page_size(mach_port, &page_size) &&
		KERN_SUCCESS == host_statistics64(mach_port, HOST_VM_INFO,
		(host_info64_t)&vm_stats, &count))
	{
		long long free_memory = static_cast<int64_t>(vm_stats.free_count) * static_cast<int64_t>(page_size);
		long long used_memory = (static_cast<int64_t>(vm_stats.active_count) +
			static_cast<int64_t>(vm_stats.inactive_count) +
			static_cast<int64_t>(vm_stats.wire_count)) * static_cast<int64_t>(page_size);
		mvprintw(y, 0, "Free memory:  %lld", free_memory);
		mvprintw(y + 1, 0, "Used memory:  %lld", used_memory);
	}
	mvprintw(y + 2, 0, "Total memory: %llu", get_mem());
}

int		RAM::getHeigh(void) const
{
		return (this->_heigh);
}
