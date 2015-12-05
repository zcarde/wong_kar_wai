/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_cols.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:46:16 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/01 07:46:52 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deuxquatrehuit.h"

void	print_col(int x, int line_size, char c)
{
	int y;

	y = 1;
	while (y < line_size * SIZE + SIZE)
	{
		mvprintw(y, x, &c);
		y++;
	}
}

void	print_cols(int x, int col_size, int line_size)
{
	int j;
	int nb;

	nb = 0;
	j = 1;
	attron(COLOR_PAIR(1));
	while (j < x - 1)
	{
		if (j % (col_size + 1) == 0 || nb >= SIZE)
		{
			print_col(j, line_size, ' ');
			nb++;
		}
		j++;
	}
	attroff(COLOR_PAIR(1));
}
