/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_cot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 13:17:27 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/21 20:05:36 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/21sh.h"

int		check_cot(const char *str)
{
    int i;
    int ck;
    int ck2;
    int ret;

    i = 0;
    ck = 0;
    ck2 = 0;
    while (str[i])
    {
        if (str[i] == '"')
            ck++;
        if (str[i] == 39)
            ck2++;
        i++;
    }
    ret = (((ck % 2 ) == 0)) ? 0 : 1;
    ret = (((ck2 % 2 ) == 0)) ? 0 : 1;
    return (ret);
}