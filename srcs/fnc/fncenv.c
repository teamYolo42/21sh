/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncenv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/16 17:26:02 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/05 12:45:27 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/21sh.h"

static int	ft_strstartswith(char *s1, char *s2)
{
	int	i;

	i = -1;
	while (s2[++i])
		if (s1[i] != s2[i])
			return (0);
	return (1);
}

int			find_env_var(char **env, char *var)
{
	int		i;
	char	*tmp;

	i = -1;
	while (env[++i])
	{
		tmp = ft_strjoin(var, "=");
		if (ft_strstartswith(env[i], tmp))
		{
			free(tmp);
			return (i);
		}
		free(tmp);
	}
	return (i);
}

char		*ft_getenv_2(char **env, char *str)
{
	int			i;
	size_t		start;
	size_t		len;
	char		*tmp;

	i = -1;
	tmp = NULL;
	if (!str || !(tmp = ft_strjoin(str, "=")))
		return (NULL);
	start = ft_strlen(tmp);
	while (env && env[++i])
	{
		if (!(ft_strncmp(env[i], tmp, start)))
		{
			free(tmp);
			len = ft_strlen(ft_strchr(env[i], '='));
			return (ft_strsub(env[i], start, len));
		}
	}
	free(tmp);
	return (NULL);
}

char		*ft_getenv(char ***env, char *var)
{
	char	**tmp;
	char	*str;
	int		i;

	i = 0;
	tmp = *env;
	while (tmp[i])
	{
		if ((ft_strncmp(tmp[i], var, ft_strlen(var))) == 0)
		{
			str = ft_strdup(tmp[i]);
			str = ft_cut(str, '=');
			return (str);
		}
		i++;
	}
	return (NULL);
}
