/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:40:43 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/01 07:53:51 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deuxquatrehuit.h"

int		go_win(t_var *vars)
{
	int touch;

	fill_line_with_space(vars);
	mvprintw(vars->y_win - 2, 2,
			"Congratulation %s you winned with %d points\
, do you want to continue ? [y/n/r(restart)]",
			vars->scores.log, vars->scores.score);
	vars->scores.winned = 1;
	while ((touch = getch()) != 'y' && touch != 'n' && touch != 'r')
	{
		if (draw_boxes(vars))
			mvprintw(vars->y_win - 2, 2,
			"Congratulation %s you winned with %d points\
, do you want to continue ? [y/n/r(restart)]",
			vars->scores.log, vars->scores.score);
	}
	fill_line_with_space(vars);
	draw_boxes(vars);
	if (touch == 'y')
		return (1);
	else if (touch == 'n')
		return (-1);
	else
		return (0);
}

int		check_win(t_var *vars)
{
	int i;
	int j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (vars->map[i][j] == WIN_VALUE)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
