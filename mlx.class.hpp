#ifndef MLX_CLASS_HPP
# define MLX_CLASS_HPP

# include <iostream>
# include <string>
# include "CPU.hpp"
# include "Name.hpp"
# include "Date.hpp"
# include "Network.hpp"
# include "RAM.hpp"
# include "Os_info.hpp"
# include "IMonitorDisplay.hpp"

class mlx: public IMonitorDisplay
{
	public:

		mlx(void);
		virtual ~mlx(void);

		virtual void	init(void);
		virtual int		getKey(CPU const & cpu, Name const & name, Date const & date, Network const & net, RAM const & ram, Os_info const & os);
		virtual void	start(void);

	private:

		int		_pos[6];
		int		_y;
		int		_module;
		mlx(const mlx & interface);
		mlx &operator=(const mlx & interface);
};

#endif
