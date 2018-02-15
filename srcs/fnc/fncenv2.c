/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncenv2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/09 19:15:25 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/12 17:50:46 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minishell.h"

static	char		**addenv_env(char **env, char *name, char *value)
{
	char	*str;

	str = ft_strdup(name);
	str = ft_strjoinfrees1(str, "=");
	str = ft_strjoinfrees1(str, value);
	env = ft_reallocd(env, 1, str);
	free(str);
	return (env);
}

static char			**fillenv_env(char **env, char *name, char *value, int j)
{
	char	*str;

	str = ft_strdup(name);
	str = ft_strjoinfrees1(str, "=");
	str = ft_strjoinfrees1(str, value);
	ft_bzero(env[j], ft_strlen(env[j]));
	env[j] = ft_strjoinfree(env[j], str);
	return (env);
}

static int			parseenv_env(char ***env, char *value, char *name, int ov)
{
	int		j;
	char	**tmp;

	j = 0;
	tmp = *env;
	while (tmp[j])
	{
		if (ft_strcmpcuts1(tmp[j], name, '=') == 0)
		{
			if (ov != 0)
				*env = fillenv_env(*env, name, value, j);
			return (0);
		}
		j++;
	}
	return (1);
}

static	int			checksyntax_env(const char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '=' && str[i] != ' ')
		i++;
	if (str[i] == '=')
	{
		i++;
		if (!str[i])
			return (1);
		while (str[i] != ' ' && str[i])
			i++;
		if (!str[i])
			return (-1);
		i++;
		if ((!str[i] || str[i] == '0' || str[i] == '1') && !str[i + 1])
			return (0);
		else
			return (1);
	}
	else
		return (1);
}

int					ft_setenv_env(char ***env, char *str)
{
	int		in[2];
	char	*name;
	char	*value;

	if ((in[0] = checksyntax_env(str)) == 1)
		return (1);
	if (in[0] == -1)
		in[1] = 0;
	else
		in[1] = ft_atoi(ft_strchr(str, ' '));
	name = ft_strgetchartc(str, '=');
	value = ft_cut(str, '=');
	if (in[0] != -1)
		value = ft_strgetchartc(str, ' ');
	if (parseenv_env(env, value, name, 1))
		*env = addenv_env(*env, name, value);
	else
		return (1);
	free(name);
	if (in[0] != -1)
		free(value);
	return (0);
}
