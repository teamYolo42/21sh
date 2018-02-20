/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_setenv2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 18:11:17 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/20 18:11:17 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/21sh.h"

char	**addenv(char *name, char *value)
{
    char	*str;

    str = ft_strdup(name);
    str = ft_strjoinfrees1(str, "=");
    str = ft_strjoinfrees1(str, value);
    g_env = ft_reallocd(g_env, 1, str);
    free(str);
    return (g_env);
}

char			**fillenv(char *name, char *value, int j)
{
    char	*str;

    str = ft_strdup(name);
    str = ft_strjoinfrees1(str, "=");
    str = ft_strjoinfrees1(str, value);
    ft_bzero(g_env[j], ft_strlen(g_env[j]));
    g_env[j] = ft_strjoinfree(g_env[j], str);
    return (g_env);
}

int				parseenv(char *value, char *name, int overwrite)
{
    int		j;
    char	**tmp;

    j = 0;
    tmp = g_env;
    while (tmp[j])
    {
        if (ft_strcmpcuts1(tmp[j], name, '=') == 0)
        {
            if (overwrite != 0)
                g_env = fillenv(name, value, j);
            return (0);
        }
        j++;
    }
    return (1);
}