/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:37:53 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/20 11:41:47 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

char    *ft_joinsplitc(char **split, int i, char c)
{
    char *ret;

    ret = ft_strdup(split[i]);
    while (split[i] && split[i + 1])
    {
        ret = ft_strjoincfree(ret, c);
        ret = ft_strjoinfrees1(ret, split[i + 1]);
        i++;
    }
    return (ret);
}

char    *ft_joinsplit(char **split, int i)
{
    char *ret;

    ret = ft_strdup(split[i]);
    while (split[i] && split[i + 1])
    {
        ret = ft_strjoinfrees1(ret, split[i + 1]);
        i++;
    }
    return (ret);
}