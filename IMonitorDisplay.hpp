#ifndef IMONITORDISPLAY_HPP
# define IMONITORDISPLAY_HPP

class IMonitorDisplay
{
	public:
		virtual void init( void );
		virtual int getKey( CPU const & cpu, Name const & name, Date const & date, Network const & net, RAM const & ram, Os_info const & os );
		virtual void start(void);
};

#endif
