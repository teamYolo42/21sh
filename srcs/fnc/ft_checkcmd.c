/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ckeckcmd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/16 18:10:21 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/16 18:10:21 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/21sh.h"

int ft_checkcmd(char *cmd, char *str)
{
    if (ft_strcmp(str, cmd) == 0)
        return (1);
    else
    {
        ft_error("","command not found");
        return (0);
    }
}