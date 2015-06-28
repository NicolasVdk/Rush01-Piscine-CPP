#include "mlx.class.hpp"
#include <curses.h>
#include <ctime>
#include <unistd.h>

#define ESCAPE	27
#define RESET	330
#define MOD1	49
#define MOD2	50
#define MOD3	51
#define MOD4	52
#define MOD5	53
#define MOD6	54

mlx::mlx(void) : _y(0), _module(0)
{
	return ;
}

mlx::~mlx(void)
{
	endwin();
	return ;
}

void	mlx::init(void)
{
	initscr();
	start_color();
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_BLUE, COLOR_BLUE);
	init_pair(3, COLOR_BLACK, COLOR_BLACK);
	init_pair(4, COLOR_RED, COLOR_RED);
	init_pair(5, COLOR_GREEN, COLOR_GREEN);
	init_pair(6, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(7, COLOR_WHITE, COLOR_BLACK);
	init_pair(8, COLOR_BLUE, COLOR_BLACK);
	init_pair(9, COLOR_RED, COLOR_BLACK);
	init_pair(10, COLOR_YELLOW, COLOR_BLACK);
	init_pair(11, COLOR_GREEN, COLOR_BLACK);
	init_color(12, 300, 300, 300);
	init_pair(13, 12, COLOR_BLACK);
	init_pair(14, COLOR_CYAN, COLOR_BLACK);
	curs_set(0);
	noecho();
	nodelay(stdscr, TRUE);
	keypad(stdscr, TRUE);
}

int		mlx::getKey(CPU const & cpu, Name const & name, Date const & date, Network const & net, RAM const & ram, Os_info const & os)
{
	int		key = 0;

	switch ((key = getch()))
	{
		case MOD1:
			if (!(this->_module & (1 << 1)))
			{
				this->_module |= 1 << 1;
				this->_pos[0] = this->_y;
				this->_y += cpu.getHeigh();
			}
			break ;
		case MOD2:
			if (!(this->_module & (1 << 2)))
			{
				this->_module |= 1 << 2;
				this->_pos[1] = this->_y;
				this->_y += name.getHeigh();
			}
			break ;
		case MOD3:
			if (!(this->_module & (1 << 3)))
			{
				this->_module |= 1 << 3;
				this->_pos[2] = this->_y;
				this->_y += date.getHeigh();
			}
			break ;
		case MOD4:
			if (!(this->_module & (1 << 4)))
			{
				this->_module |= 1 << 4;
				this->_pos[3] = this->_y;
				this->_y += net.getHeigh();
			}
			break ;
		case MOD5:
			if (!(this->_module & (1 << 5)))
			{
				this->_module |= 1 << 5;
				this->_pos[4] = this->_y;
				this->_y += ram.getHeigh();
			}
			break ;
		case MOD6:
			if (!(this->_module & (1 << 6)))
			{
				this->_module |= 1 << 6;
				this->_pos[5] = this->_y;
				this->_y += os.getHeigh();
			}
			break ;
		case RESET:
			this->_y = 0;
			this->_module = 0;
			break ;
		//default: mvprintw(0, 0, "key: %d", key);
	}
	return (key);
}

void	mlx::start(void)
{
	int		key;
	CPU		cpu;
	RAM		ram;
	Name	name;
	Date	date;
	Network	net;
	Os_info	os;

	this->init();
	while ((key = this->getKey(cpu, name, date, net, ram, os)) != ESCAPE)
	{
		erase();
		if (this->_module & (1 << 1))
			cpu.displayMlx(this->_pos[0]);
		if (this->_module & (1 << 2))
			name.displayMlx(this->_pos[1]);
		if (this->_module & (1 << 3))
			date.displayMlx(this->_pos[2]);
		if (this->_module & (1 << 4))
			net.displayMlx(this->_pos[3]);
		if (this->_module & (1 << 5))
			ram.displayMlx(this->_pos[4]);
		if (this->_module & (1 << 6))
			os.displayMlx(this->_pos[5]);
		wrefresh(stdscr);
		sleep(1);
	}
}
