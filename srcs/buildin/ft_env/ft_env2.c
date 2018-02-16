/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:48:16 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/16 19:24:20 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/21sh.h"

void    ft_put_merge_env(char **envi, char **split)
{
    int     i;
    char    **env;

    i = 0;
    env = ft_strdupdup(envi);
    while (split[i] && ft_setenv_env(&env, split[i]) == 0)
        i++;
    ft_puttab(env);
    freer(env);
}