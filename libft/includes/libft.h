/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asandolo <asandolo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 10:27:54 by asandolo          #+#    #+#             */
/*   Updated: 2018/02/09 10:52:29 by asandolo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <limits.h>
# include <stdlib.h>
# include "color.h"

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

void				*ft_memset(void *b, int c, size_t len);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dst, const void *src, size_t n);
void				*ft_memccpy(void *dst, const void *src, int c, size_t n);
void				*ft_memmove(void *dst, const void *src, size_t len);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
size_t				ft_strlen(const char *s);
char				*ft_strdup(const char *s1);
char				*ft_strcpy(char *dst, const char *src);
char				*ft_strncpy(char *dst, const char *src, size_t len);
char				*ft_strcat(char *s1, const char *s2);
char				*ft_strncat(char *s1, const char *s2, size_t n);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *s, int c);
char				*ft_strrchr(const char *s, int c);
char				*ft_strstr(const char *haystack, const char *needle);
char				*ft_strnstr(const char *s1, const char *s2, size_t len);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(const char *s1, const char *s2, size_t n);
int					ft_atoi(const char *str);
int					ft_isalpha(int c);
int					ft_isdigit(int c);
int					ft_isalnum(int c);
int					ft_isascii(int c);
int					ft_isprint(int c);
int					ft_toupper(int c);
int					ft_tolower(int c);

void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
char				**ft_strsplit(char const *s, char c);
char				*ft_itoa(int n);
void				ft_putchar(char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char const *s, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);

t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void				ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void				ft_lstadd(t_list **alst, t_list *n);
void				ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));

int					ft_isupper(int c);
int					ft_islower(int c);
int					ft_isnegativ(int n);
int					ft_min(int a, int b);
int					ft_max(int a, int b);
char				*ft_strrev(char *str);
void				ft_putofft(off_t nb);
void				ft_putuint(unsigned int nb);
void				ft_putnstr(const char *s, size_t n);
char				*ft_strrchrwc(const char *s, int c);
void				ft_putlong(long nb);
char				*ft_strchrwa(const char *s, int c);
char				*ft_strrchrwa(const char *s, int c);
char				*ft_ltoa(long n);
int					ft_nbint(int nbr);
off_t				ft_nbofft(off_t nbr);
size_t				ft_nbsize_t(size_t nbr);
void				ft_delchar(char *str, char c);
void				ft_putcolormultistr(char *color, char *a, char *b, char *c);
void				*ft_reallocd(char **ptr, int size, char *newstr);
void				*ft_realloc(void *ptr, int size);
char				*ft_cut(char *name, char c);
void				ft_strcut(char *str, int i);
void				ft_putcolormultistr_err(char *r, char *a, char *b, char *c);
size_t				ft_countwords(const char *str, char sep);
char				*ft_strgetchartc(char *str, char c);
char				*ft_strjoinfree(char *s1, char *s2);
char				*ft_strjoinfrees1(char *s1, char *s2);
char				*ft_strjoinfrees2(char *s1, char *s2);
int					ft_strcmpcuts1(char *s1, char *s2, char c);
char				*epur_str(char *str);
char				*epur_str_free(char *str);
char				*ft_strgetstatic(char *str, int *next, char c);
char				*ft_strgetchartc_nm(char *str, char c);
void				ft_replacechar(char *str, char c1, char c2);
char				**ft_strdupdup(char **str);
char				*ft_strjoinc(char *s, char c);
char				*ft_strjoincfree(char *s, char c);

#endif