/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zcarde <zcarde@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/01 07:47:15 by zcarde            #+#    #+#             */
/*   Updated: 2015/03/04 02:46:18 by zcarde           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "deuxquatrehuit.h"

void		signal_handler(int sig)
{
	(void)sig;
	reset_color();
	endwin();
	signal(SIGINT, SIG_DFL);
	raise(sig);
}

void		signal_catchs(void)
{
	signal(SIGINT, signal_handler);
	signal(SIGKILL, signal_handler);
	signal(SIGABRT, signal_handler);
	signal(SIGSEGV, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGQUIT, signal_handler);
}
