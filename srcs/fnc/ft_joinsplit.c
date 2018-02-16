/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_joinsplit.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:37:53 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/16 18:43:20 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/21sh.h"

char    *ft_joinsplit(char **split, int i)
{
    char *ret;

    ret = ft_strdup(split[i]);
    while (split[i] && split[i + 1])
    {
        ret = ft_strjoincfree(ret, ' ');
        ret = ft_strjoinfrees1(ret, split[i + 1]);
        i++;
    }
    return (ret);
}