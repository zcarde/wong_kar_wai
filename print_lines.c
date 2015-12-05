/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_lines.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:45:53 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/01 07:46:09 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deuxquatrehuit.h"

void	print_line(int y, int x_max, char c)
{
	int x;

	x = 1;
	while (x < x_max - 1)
	{
		mvprintw(y, x, &c);
		x++;
	}
}

void	print_lines(int x, int y, int line_size)
{
	int i;
	int nb;

	nb = 0;
	i = 1;
	attron(COLOR_PAIR(1));
	print_line(y - 3, x, ' ');
	while (i < y - 3)
	{
		if (i % (line_size + 1) == 0 || nb >= SIZE)
		{
			print_line(i, x, ' ');
			nb++;
		}
		i++;
	}
	attroff(COLOR_PAIR(1));
}
