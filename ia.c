/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ia.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:38:59 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/01 07:39:19 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deuxquatrehuit.h"

int		go_ia(t_var *vars)
{
	int ret;

	while (1)
	{
		if (check_win(vars) == 1 && vars->scores.winned == 0)
			break ;
		ret = left(vars);
		draw_boxes(vars);
		if (ret == 1)
			down(vars);
		else if (ret == 0 && down(vars) == 0)
		{
			if (right(vars) == 0)
			{
				if (up(vars) == 0)
					return (0);
			}
		}
		draw_boxes(vars);
		usleep(500000);
	}
	return (1);
}
