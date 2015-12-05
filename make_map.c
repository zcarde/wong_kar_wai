/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:47:46 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/01 07:48:09 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deuxquatrehuit.h"

int		**make_map(void)
{
	int		**map;
	int		i;
	int		j;

	map = (int **)malloc(sizeof(int *) * SIZE);
	i = 0;
	while (i < SIZE)
	{
		map[i] = (int *)malloc(sizeof(int) * SIZE);
		i++;
	}
	i = 0;
	while (i < SIZE)
	{
		j = 0;
		while (j < SIZE)
		{
			map[i][j] = 0;
			j++;
		}
		i++;
	}
	return (map);
}

void	put_rand(int ***map)
{
	int		i;
	int		j;
	int		value;

	i = (int)(rand() % SIZE);
	j = (int)(rand() % SIZE);
	value = ((int)(rand() % 10) < 8 ? 2 : 4);
	while (1)
	{
		if ((*map)[i][j] == 0)
		{
			(*map)[i][j] = value;
			break ;
		}
		else
		{
			i = (int)(rand() % SIZE);
			j = (int)(rand() % SIZE);
		}
	}
}
