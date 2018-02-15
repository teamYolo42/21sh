/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_starting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:42:40 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/12 17:49:40 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/21sh.h"

void	ft_starting(void)
{
	char	*lvl;
	int		ilvl;

	lvl = ft_getenv(&g_env, "SHLVL");
	if (lvl)
	{
		ilvl = ft_atoi(lvl);
		ilvl++;
		free(lvl);
		lvl = ft_itoa(ilvl);
		g_env = fillenv("SHLVL", lvl, find_env_var(g_env, "SHLVL"));
		free(lvl);
	}
}
