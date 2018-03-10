/*
** my_gettenv.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Tue Jan 17 20:13:23 2017 Thomas BLENEAU
** Last update Sat Jan 21 20:10:31 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

char	*my_getenv(char *str, char **env)
{
  int	i;
  int	size;

  i = -1;
  if (env == NULL || str == NULL)
    return (NULL);
  size = my_strlen(str);
  while (env[++i] != NULL)
    {
      if (my_strncmp(env[i], str, size) == 0)
	return (&env[i][size + 1]);
    }
  return (NULL);
}
