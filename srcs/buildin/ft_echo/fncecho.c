/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fncecho.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/07 19:41:55 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/12 17:49:05 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../includes/21sh.h"

int	ft_env_len(char *str, int i)
{
	while (str[i] && !ft_ispace(str[i]))
		i++;
	return (i);
}


int		ft_92(const char *str, int k)
{
    if (str[k + 1] == 'a' || str[k + 1] == 'b' || str[k + 1] == 't' ||
        str[k + 1] == 'n' || str[k + 1] == 'v' || str[k + 1] == 'f' ||
        str[k + 1] == 'r' || str[k + 1] == 92)
    {
        if (str[k + 1] && str[k + 1] == 'a')
            ft_putchar('\a');
        if (str[k + 1] && str[k + 1] == 'b')
            ft_putchar('\b');
        if (str[k + 1] && str[k + 1] == 't')
            ft_putchar('\t');
        if (str[k + 1] && str[k + 1] == 'n')
            ft_putchar('\n');
        if (str[k + 1] && str[k + 1] == 'v')
            ft_putchar('\v');
        if (str[k + 1] && str[k + 1] == 'f')
            ft_putchar('\f');
        if (str[k + 1] && str[k + 1] == 'r')
            ft_putchar('\r');
        if (str[k + 1] && str[k + 1] == 92)
            ft_putchar(92);
        return (1);
    }
    return (0);
}