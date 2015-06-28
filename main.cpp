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

int		main( void )
{
	Interface *interface = new Interface;
	interface->start();
	delete interface;
	return (0);
}
