#ifndef INTERFACE_CLASS_HPP
# define INTERFACE_CLASS_HPP

# include <iostream>
# include <string>
# include "CPU.hpp"
# include "Name.hpp"
# include "Date.hpp"

class Interface
{
	public:

		Interface(void);
		~Interface(void);

		void	init_ncurse(void);
		int		getKey(CPU const & cpu, Name const & name, Date const & date);
		void	start(void);

	private:

		int		_pos[6];
		int		_y;
		int		_module;
		Interface(const Interface & interface);
		Interface &operator=(const Interface & interface);
};

#endif
