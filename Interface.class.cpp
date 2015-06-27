#include "Interface.class.hpp"
#include <curses.h>
#include <ctime>
#include <unistd.h>

#define ESCAPE 27
#define MOD1	49
#define MOD2	50
#define MOD3	51
#define MOD4	52
#define MOD5	53
#define MOD6	54

Interface::Interface(void) : _y(0), _module(0)
{
	return ;
}

Interface::~Interface(void)
{
	endwin();
	return ;
}

void	Interface::init_ncurse(void)
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

int		Interface::getKey(CPU const & cpu, Name const & name, Date const & date)
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
		/*case MOD4:
			this->_module |= 4 << 1;
			(!(this->_module & (4 << 1))) ? this->_y += ram->getHeigh() : ;
			break ;
		case MOD5:
			this->_module |= 5 << 1;
			(!(this->_module & (5 << 1))) ? this->_y += ram->getHeigh() :  ;
			break ;
		case MOD6: this->_module |= 6 << 1;
			(!(this->_module & (6 << 1))) ? this->_y += ram->getHeigh() : ;
			break ;
		//default: mvprintw(0, 0, "key: %d", key);
		*/
	}
	return (key);
}

void	Interface::start(void)
{
	int		key;
	CPU		cpu;
	//Ram		ram;
	Name	name;
	Date	date;

	this->init_ncurse();
	while ((key = this->getKey(cpu, name, date)) != ESCAPE)
	{
		erase();
		if (this->_module & (1 << 1))
			cpu.display(this->_pos[0]);
		if (this->_module & (1 << 2))
			name.display(this->_pos[1]);
		if (this->_module & (1 << 3))
			date.display(this->_pos[2]);
		/*if (this->module & (4 << 1))
			cpu.display(this->pos[3]);
		if (this->module & (5 << 1))
			cpu.display(this->pos[4]);
		if (this->module & (6 << 1))
			cpu.display(this->pos[5]);
		*/
		wrefresh(stdscr);
		sleep(1);
	}
}
