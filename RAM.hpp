#ifndef RAM_HPP
# define RAM_HPP

# include "IMonitorModule.hpp"

class RAM : public IMonitorModule
{
	public:
		RAM();
		~RAM();
		virtual int		getHeigh( void ) const;
		virtual void	display( void );

	private:
		RAM &		operator=(RAM const & rhs);
		RAM(RAM const & src);
		int		_heigh;
};

#endif