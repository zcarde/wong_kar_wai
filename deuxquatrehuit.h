/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deuxquatrehuit.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/02/27 21:50:20 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/04 02:05:03 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEUXQUATREHUIT_H
# define DEUXQUATREHUIT_H

# include <stdlib.h>
# include <time.h>
# include <ncurses.h>
# include <signal.h>
# include <unistd.h>
# include "libft.h"

enum			e_const
{
	WIN_VALUE = 2048,
	SIZE = 4,
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4
};

typedef struct	s_sc
{
	char		*log;
	long		score;
	int			winned;
}				t_sc;

typedef struct	s_var
{
	t_sc		scores;
	int			**map;
	short		colors[8];
	int			x_win;
	int			y_win;
	int			ia_activated;
}				t_var;

void			draw_box(int x, int y);
int				draw_boxes(t_var *vars);
void			fill_line_with_space(t_var *vars);

int				checks(void);

int				main(int ac, char **av, char **env);

int				down(t_var *vars);
int				move_down(t_var *vars, int j, int i, int *last_line);
int				down_key(t_var *vars);

int				go_ia(t_var *vars);

void			init_pairs(void);
void			init_colors(void);
void			reset_color(void);
int				get_color(int nb);

int				left(t_var *vars);
int				move_left(t_var *vars, int j, int i, int *last_col);
int				left_key(t_var *vars);

int				go_loose(t_var *vars);
int				check_loose(t_var *vars);

int				**make_map(void);
void			put_rand(int ***map);

void			print_col(int x, int line_size, char c);
void			print_cols(int x, int col_size, int line_size);

void			print_line(int y, int x_max, char c);
void			print_lines(int x, int y, int line_size);

void			print_grid(int x, int y);
void			fill_rect(int x_min, int x_max, int y_min, int y_max);
void			fill_case(int y, int x, t_var *vars);
void			print_number(int y, int x, int nb);
void			print_tab(int x, int y, t_var *vars);

int				restart(t_var *vars);

int				right(t_var *vars);
int				move_right(t_var *vars, int j, int i, int *last_col);
int				right_key(t_var *vars);

void			signal_handler(int sig);
void			signal_catchs(void);

int				up(t_var *vars);
int				move_up(t_var *vars, int j, int i, int *last_line);
int				up_key(t_var *vars);

int				go_win(t_var *vars);
int				check_win(t_var *vars);

#endif
