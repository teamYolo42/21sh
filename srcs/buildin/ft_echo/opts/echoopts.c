#include "../../../../includes/21sh.h"

static int			add_options(char *optecho, const char *new)
{
    int		i;

    i = 1;
    while (new[i] != '\0')
    {
        if (new[i] == 'n')
            OPT_ECHO_N = 1;
        else
        {
            ft_erroru("env ", "Illegal argument", " env [-i] [key=var..] binany");
            return (-1);
        }
        i++;
    }
    return (1);
}

int					get_options_echo(char *optecho, char **argv, int argc)
{
    int		i;

    i = 1;
    ft_bzero(optecho, 1);
    while (i < argc && argv[i][0] == '-' && argv[i][1] != '\0')
    {
        if (add_options(optecho, argv[i]) == -1)
            return (-1);
        i++;
    }
    return (i);
}