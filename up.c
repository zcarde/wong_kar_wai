/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   up.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:41:41 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/01 07:42:15 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deuxquatrehuit.h"

int		up(t_var *vars)
{
	if (up_key(vars))
	{
		put_rand(&(vars->map));
		return (1);
	}
	return (0);
}

int		move_up(t_var *vars, int j, int i, int *last_line)
{
	if (vars->map[i][j] == vars->map[i - 1][j] && vars->map[i][j] != 0)
	{
		vars->map[i - 1][j] *= 2;
		vars->map[i][j] = 0;
		*last_line = i;
		vars->scores.score += vars->map[i - 1][j];
		return (1);
	}
	else if (vars->map[i - 1][j] == 0 && vars->map[i][j] != 0)
	{
		vars->map[i - 1][j] = vars->map[i][j];
		vars->map[i][j] = 0;
		return (1);
	}
	return (0);
}

int		up_key(t_var *vars)
{
	int i;
	int j;
	int last_line;
	int k;
	int moved;

	j = 0;
	moved = 0;
	while (j < SIZE)
	{
		i = 1;
		last_line = 0;
		while (i < SIZE)
		{
			k = i;
			while (k > last_line)
			{
				if (move_up(vars, j, k--, &last_line) == 1)
					moved = 1;
			}
			i++;
		}
		j++;
	}
	return (moved);
}
