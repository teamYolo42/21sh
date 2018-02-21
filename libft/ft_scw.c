/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scw.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 23:03:35 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/21 23:05:34 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

size_t	ft_scountwords(const char *str, char c)
{
    size_t  word;
    int     i;
    char    x;

    i = 0;
    word = 0;
    if (!str)
        return (0);
    while (str[i])
    {
        if (str[i] == '"' || str[i] == 39)
        {
            x = str[i];
            i++;
            while (str[i] != x)
                i++;
        }
        else  if (str[i] == c && str[i + 1] != c)
            word++;
        i++;
    }
    if (str[0] != '\0')
        word++;
    return (word);
}