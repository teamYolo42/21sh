/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sig_kill.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 16:10:35 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/12 17:59:39 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

void	ft_sig_kill(int sig)
{
	if (sig == 2)
	{
		if (g_pid != 0)
			kill(g_pid, 9);
		ft_putchar('\n');
		if (g_pid == 0)
			ft_affprompt();
		g_pid = 0;
	}
}
