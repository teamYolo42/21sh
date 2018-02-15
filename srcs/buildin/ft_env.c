/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/12 13:15:07 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/12 17:47:26 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static void			put_env(char **env)
{
	int		i;

	i = 0;
	while (env[i])
	{
		ft_putendl(env[i]);
		i++;
	}
}

static	void		ft_env2(char *str)
{
	char	**env;
	char	**split;
	int		i;
	char	*tmp;

	i = 0;
	env = ft_strdupdup(g_env);
	split = ft_strsplit(str, ' ');
	while (split[i] && ft_setenv_env(&env, split[i]) == 0)
		i++;
	if (split[i])
	{
		tmp = ft_strdup(split[i]);
		while (split[i] && split[i + 1])
		{
			tmp = ft_strjoincfree(tmp, ' ');
			tmp = ft_strjoinfrees1(tmp, split[i + 1]);
			i++;
		}
		go(&env, tmp, 1);
		free(tmp);
	}
	freer(env);
	freer(split);
}

void				ft_env(char ***env, char *str)
{
	ft_strcut(str, 3);
	if (!ft_ispace(str[0]))
	{
		if (ft_strcmp(str, "") == 0)
			put_env(*env);
		else
		{
			ft_error("Error: ", "command not found");
			return ;
		}
	}
	else
		ft_env2(str);
}
