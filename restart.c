/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:52:39 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/01 07:52:57 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deuxquatrehuit.h"

int		restart(t_var *vars)
{
	int i;
	int j;

	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			vars->map[i][j] = 0;
			j++;
		}
		i++;
	}
	vars->scores.score = 0;
	put_rand(&(vars->map));
	put_rand(&(vars->map));
	vars->scores.winned = 0;
	clear();
	draw_boxes(vars);
	refresh();
	vars->ia_activated = 0;
	return (1);
}
