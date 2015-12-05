/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loose.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:39:32 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/01 07:40:26 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deuxquatrehuit.h"

int		go_loose(t_var *vars)
{
	int touch;

	fill_line_with_space(vars);
	mvprintw(vars->y_win - 2, 2,
	"Sorry for you %s, you loosed with %d points, do you want to retry [y/n]?"
		, vars->scores.log, vars->scores.score);
	vars->scores.winned = 1;
	while ((touch = getch()) != 'y' && touch != 'n')
	{
		if (draw_boxes(vars))
			mvprintw(vars->y_win - 2, 2,
	"Sorry for you %s, you loosed with %d points, do you want to retry [y/n]?"
			, vars->scores.log, vars->scores.score);
	}
	fill_line_with_space(vars);
	draw_boxes(vars);
	if (touch == 'y')
		return (1);
	else
		return (-1);
}

int		check_loose(t_var *vars)
{
	int i;
	int j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			if (vars->map[i][j] == 0)
				return (0);
			if (i < SIZE - 1 && vars->map[i + 1][j] == vars->map[i][j])
				return (0);
			if (j < SIZE - 1 && vars->map[i][j + 1] == vars->map[i][j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
