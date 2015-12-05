/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:45:12 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/01 07:45:37 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deuxquatrehuit.h"

int		right(t_var *vars)
{
	if (right_key(vars))
	{
		put_rand(&(vars->map));
		return (1);
	}
	return (0);
}

int		move_right(t_var *vars, int j, int i, int *last_col)
{
	if (vars->map[i][j] == vars->map[i][j + 1] && vars->map[i][j] != 0)
	{
		vars->map[i][j + 1] *= 2;
		vars->map[i][j] = 0;
		*last_col = j;
		vars->scores.score += vars->map[i][j + 1];
		return (1);
	}
	else if (vars->map[i][j + 1] == 0 && vars->map[i][j] != 0)
	{
		vars->map[i][j + 1] = vars->map[i][j];
		vars->map[i][j] = 0;
		return (1);
	}
	return (0);
}

int		right_key(t_var *vars)
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
		j = SIZE - 2;
		last_col = SIZE - 1;
		while (j >= 0)
		{
			k = j;
			while (k < last_col)
			{
				if (move_right(vars, k++, i, &last_col) == 1)
					moved = 1;
			}
			j--;
		}
		i++;
	}
	return (moved);
}
