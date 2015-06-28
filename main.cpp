/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kperreau <kperreau@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/27 18:32:50 by kperreau          #+#    #+#             */
/*   Updated: 2015/06/28 03:32:59 by kperreau         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Interface.class.hpp"
#include <mlx.h>

int		main(int argc, char **argv)
{

	if (argc > 1 && !strcmp(argv[1], "-mlx"))
	{
		//interface = new mlx;
		char name[] = "ft_";
		int	width = 500;
		int	height = 800;
		void *mlx;
		int bpp = 24;
		int endian = 1;
		void *win;
		void *img;
		char *data;

		if (!(mlx = mlx_init()))
			return (1);
		win = mlx_new_window(mlx, width, height, name);
		img = mlx_new_image(mlx, width, height);
		data = mlx_get_data_addr(img, &bpp, &width, &endian);
		mlx_put_image_to_window(mlx, win, img, 0, 0);
		mlx_loop(mlx);
	}
	else
	{
		Interface *interface = new Interface;
		interface->start();
		delete interface;
	}
	return (0);
}
