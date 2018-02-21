/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specialsplt.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 21:17:41 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/21 23:00:25 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

static  int             ft_count_words(const char *str, char c)
{
    int     word;
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

int ft_w2(const char *str, int *i, int k, char **s)
{
    char x;

    x = str[*i];
    (*s)[k++] = x;
    *i += 1;
    while (str[*i] && str[*i] != x)
    {
        (*s)[k++] = str[*i];
        *i += 1;
    }
    (*s)[k++] = x;
    *i += 1;
    return (k);
}

static  char    *ft_word(char *str, char c, int *i, int k)
{
    char    *s;

    if (!(s = (char *)malloc(sizeof(s) * (ft_strlen(str)))))
        return (NULL);
    if (str[*i] == '"' || str[*i] == 39)
        k = ft_w2(str, i, k, &s);
    else
        while (str[*i] && str[*i] != c)
        {
            s[k++] = str[*i];
            *i += 1;
        }
    s[k] = '\0';
    while (str[*i] == c && str[*i])
        *i += 1;
    return (s);
}

char                    **ft_specialsplit(char *str)
{
    int             i;
    int             j;
    int             wrd;
    char    **s;

    i = 0;
    j = 0;
    wrd = ft_count_words(str, ' ');
    if (!(s = (char **)malloc(sizeof(s) * (wrd + 2))))
        return (NULL);
    while (str[i] == ' ' && str[i])
        i++;
    while (j < wrd && str[i])
    {
        s[j] = ft_word(str, ' ', &i, 0);
        j++;
    }
    s[j] = NULL;
    return (s);
}