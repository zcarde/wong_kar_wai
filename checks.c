/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:53:23 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/01 07:58:58 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deuxquatrehuit.h"

static int	check_win_value(int win)
{
	int i;

	i = 2;
	while (i <= win)
		i *= 2;
	if (i == win)
		return (1);
	return (0);
}

int			checks(void)
{
	if (check_win_value(WIN_VALUE))
		ft_putendl("WIN_VALUE Not power of 2");
	else if (SIZE < 2 || SIZE > 10)
		ft_putendl("SIZE Not between 2 and 10");
	else
		return (0);
	return (1);
}
