/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borders.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:49:59 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/01 07:52:28 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deuxquatrehuit.h"

void	draw_box(int x, int y)
{
	int i;
	int j;

	i = 0;
	attron(COLOR_PAIR(1));
	while (i < y)
	{
		j = ((x - 2 - (SIZE - 1)) / SIZE) * SIZE + SIZE;
		mvprintw(i, 0, " ");
		while (j < x)
		{
			mvprintw(i, j, " ");
			j++;
		}
		i++;
	}
	j = 0;
	while (j < x)
	{
		mvprintw(y - 1, j, " ");
		mvprintw(0, j, " ");
		j++;
	}
	attroff(COLOR_PAIR(1));
}

int		draw_boxes(t_var *vars)
{
	char	*score;
	int		x;

	clear();
	getmaxyx(stdscr, vars->y_win, vars->x_win);
	if (vars->x_win - 2 < SIZE * (3 * 4) + (SIZE - 1)
		|| vars->y_win - 4 < SIZE * 5 + (SIZE - 1))
	{
		printw("Window not large enough");
		refresh();
		return (0);
	}
	score = ft_itoa(vars->scores.score);
	x = (((vars->x_win - 2 - (SIZE - 1)) / SIZE)
		* SIZE + SIZE - ft_strlen(score)) / 2 + 1;
	draw_box(vars->x_win, vars->y_win);
	print_grid(vars->x_win, vars->y_win);
	print_tab(vars->x_win, vars->y_win, vars);
	mvprintw(vars->y_win - 2, x, score);
	free(score);
	refresh();
	return (1);
}

void	fill_line_with_space(t_var *vars)
{
	int i;
	int col_size;

	i = 1;
	col_size = (vars->x_win - 2 - (SIZE - 1)) / SIZE;
	while (i < col_size * SIZE + SIZE - 1)
	{
		mvprintw(vars->y_win - 2, i, " ");
		i++;
	}
}
