/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:48:42 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/01 07:52:03 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deuxquatrehuit.h"

void	print_grid(int x, int y)
{
	int col_size;
	int line_size;

	col_size = (x - 2 - (SIZE - 1)) / SIZE;
	line_size = (y - 4 - (SIZE - 1)) / SIZE;
	print_lines(x, y, line_size);
	print_cols(x, col_size, line_size);
}

void	fill_rect(int x_min, int x_max, int y_min, int y_max)
{
	int x;
	int y;

	y = y_min;
	while (y < y_max)
	{
		x = x_min;
		while (x < x_max)
		{
			mvprintw(y, x, " ");
			x++;
		}
		y++;
	}
}

void	fill_case(int y, int x, t_var *vars)
{
	int col_size;
	int line_size;
	int i;
	int j;

	(void)vars;
	col_size = (vars->x_win - 2 - (SIZE - 1)) / SIZE;
	line_size = (vars->y_win - 4 - (SIZE - 1)) / SIZE;
	i = 1 + y + (line_size * y);
	j = 1 + x + (col_size * x);
	fill_rect(j, j + col_size, i, i + line_size);
}

void	print_number(int y, int x, int nb)
{
	mvprintw(y, x, "%d", nb);
}

void	print_tab(int x, int y, t_var *vars)
{
	int		col_size;
	int		line_size;
	int		i;
	int		j;
	char	*nbr;

	col_size = (x - 2 - (SIZE - 1)) / SIZE;
	line_size = (y - 4 - (SIZE - 1)) / SIZE;
	i = 0;
	while (i < SIZE)
	{
		j = -1;
		while (++j < SIZE)
		{
			attron(COLOR_PAIR(get_color(vars->map[i][j])));
			fill_case(i, j, vars);
			nbr = ft_itoa(vars->map[i][j]);
			print_number(i + 1 + line_size / 2 + (i * line_size)
				, j + 1 + col_size / 2 + (j * col_size) - ft_strlen(nbr) / 2,
				vars->map[i][j]);
			free(nbr);
			attroff(COLOR_PAIR(get_color(vars->map[i][j])));
		}
		i++;
	}
}
