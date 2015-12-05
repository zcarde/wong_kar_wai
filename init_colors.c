/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_colors.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:37:55 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/04 02:04:46 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deuxquatrehuit.h"

void	init_pairs(void)
{
	init_pair(1, COLOR_WHITE, COLOR_WHITE);
	init_pair(2, COLOR_WHITE, 14);
	init_pair(3, COLOR_WHITE, 1);
	init_pair(4, COLOR_WHITE, 2);
	init_pair(5, COLOR_WHITE, 3);
	init_pair(6, COLOR_WHITE, 4);
	init_pair(7, COLOR_WHITE, 5);
	init_pair(8, COLOR_WHITE, 8);
	init_pair(9, COLOR_WHITE, 9);
	init_pair(10, COLOR_WHITE, 10);
	init_pair(11, COLOR_WHITE, 11);
	init_pair(12, COLOR_WHITE, 12);
	init_pair(13, 13, 13);
}

void	init_colors(void)
{
	init_color(0, 0, 0, 0);
	init_color(14, 0, 0, 1000);
	init_color(1, 0, 100, 960);
	init_color(2, 0, 200, 920);
	init_color(3, 0, 300, 880);
	init_color(4, 0, 400, 840);
	init_color(5, 0, 500, 800);
	init_color(6, 0, 600, 760);
	init_color(8, 0, 700, 720);
	init_color(9, 0, 800, 680);
	init_color(10, 0, 900, 640);
	init_color(11, 0, 1000, 600);
	init_color(12, 0, 0, 600);
	init_color(13, 200, 200, 200);
	init_color(COLOR_WHITE, 900, 900, 900);
	init_pairs();
}

void	reset_color(void)
{
	init_color(0, 0, 0, 0);
	init_color(1, 680, 0, 0);
	init_color(2, 0, 680, 0);
	init_color(3, 680, 680, 0);
	init_color(4, 0, 0, 680);
	init_color(5, 680, 0, 680);
	init_color(6, 0, 680, 680);
	init_color(7, 680, 680, 680);
}

int		get_color(int nb)
{
	if (nb == 0)
		return (13);
	if (nb == 2)
		return (11);
	if (nb == 4)
		return (10);
	if (nb == 8)
		return (9);
	if (nb == 16)
		return (8);
	if (nb == 32)
		return (7);
	if (nb == 64)
		return (6);
	if (nb == 128)
		return (5);
	if (nb == 256)
		return (4);
	if (nb == 512)
		return (3);
	if (nb == 1024)
		return (2);
	else
		return (12);
}
