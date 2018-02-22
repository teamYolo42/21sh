/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_prompt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/08 18:25:28 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/22 14:13:10 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/21sh.h"

void	ft_affprompt(void)
{
	char *pwd;

	pwd = ft_getenv(&g_env, "PWD");
	if (pwd)
    {
        ft_putcolormultistr(_MI, "[", pwd, "]");
        ft_putcolormultistr(_G, " $>", "" , "");
        free(pwd);
    }
    else
    {
        ft_putcolormultistr(_MI, "[", "-", "]");
        ft_putcolormultistr(_G, " $>", "" , "");
    }

}
