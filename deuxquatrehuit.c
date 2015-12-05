/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deuxquatrehuit.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:50:26 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/04 02:05:53 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deuxquatrehuit.h"

static int	go_touch(int touch, t_var *vars)
{
	if (touch == KEY_UP)
		return (up(vars));
	else if (touch == KEY_DOWN)
		return (down(vars));
	else if (touch == KEY_LEFT)
		return (left(vars));
	else if (touch == KEY_RIGHT)
		return (right(vars));
	else if (touch == 'r')
		return (restart(vars));
	else
		return (0);
}

static void	part1(t_var *vars, int touch)
{
	if (draw_boxes(vars) != 0)
	{
		if (vars->ia_activated)
			go_ia(vars);
		else
			go_touch(touch, vars);
	}
	draw_boxes(vars);
}

static void	run(t_var *vars)
{
	int		touch;
	int		ret;

	draw_boxes(vars);
	while ((touch = getch()) != 27)
	{
		if (touch == 'a')
			vars->ia_activated = (vars->ia_activated) ? 0 : 1;
		part1(vars, touch);
		if (check_loose(vars))
		{
			if ((ret = go_loose(vars)) == -1)
				return ;
			else
				restart(vars);
		}
		if (!vars->scores.winned && check_win(vars))
		{
			if ((ret = go_win(vars)) == -1)
				return ;
			else if (ret == 0)
				restart(vars);
		}
		draw_boxes(vars);
	}
}

static void	init(void)
{
	initscr();
	start_color();
	keypad(stdscr, TRUE);
	noecho();
	init_colors();
	curs_set(0);
}

int			main(int ac, char **av, char **env)
{
	t_var vars;

	(void)av;
	vars.scores.score = 0;
	vars.scores.winned = 0;
	vars.ia_activated = 0;
	srand(time(NULL));
	signal_catchs();
	if (ac != 2)
	{
		ft_putendl("Usage: ./game_2048 [logname]");
		return (1);
	}
	vars.scores.log = ft_strdup(av[1]);
	if (checks())
		return (2);
	vars.map = make_map();
	put_rand(&vars.map);
	put_rand(&vars.map);
	init();
	if (env[0] == NULL)
		return (2);
	run(&vars);
	reset_color();
	endwin();
	return (0);
}
