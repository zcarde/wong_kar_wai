/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   left.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:44:00 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/01 07:45:02 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deuxquatrehuit.h"

int		left(t_var *vars)
{
	if (left_key(vars))
	{
		put_rand(&(vars->map));
		return (1);
	}
	return (0);
}

int		move_left(t_var *vars, int j, int i, int *last_col)
{
	if (vars->map[i][j] == vars->map[i][j - 1] && vars->map[i][j] != 0)
	{
		vars->map[i][j - 1] *= 2;
		vars->map[i][j] = 0;
		*last_col = j;
		vars->scores.score += vars->map[i][j - 1];
		return (1);
	}
	else if (vars->map[i][j - 1] == 0 && vars->map[i][j] != 0)
	{
		vars->map[i][j - 1] = vars->map[i][j];
		vars->map[i][j] = 0;
		return (1);
	}
	return (0);
}

int		left_key(t_var *vars)
{
	int i;
	int j;
	int last_col;
	int k;
	int moved;

	i = 0;
	moved = 0;
	while (i < SIZE)
	{
		j = 1;
		last_col = 0;
		while (j < SIZE)
		{
			k = j;
			while (k > last_col)
			{
				if (move_left(vars, k--, i, &last_col) == 1)
					moved = 1;
			}
			j++;
		}
		i++;
	}
	return (moved);
}
