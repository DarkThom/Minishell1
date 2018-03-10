/*
** my_unsetenv.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Tue Jan 17 21:14:19 2017 Thomas BLENEAU
** Last update Sun Jan 22 21:16:47 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

int	my_unsetenv(char ***env, char *name)
{
  int	i;
  char	**tab_env;

  i = 0;
  tab_env = *env;
  if (check_key(name))
    return (-1);
  else if (name == NULL || (my_strlen(name) == 0))
    return (write(2, "unsetenv: Too few arguments.\n", 29));
  while (tab_env != NULL && tab_env[i] != NULL
	 && my_strncmp(name, tab_env[i], my_strlen(name)) != 0)
    i = i + 1;
  if (tab_env[i] == NULL)
    return (-1);
  while (tab_env[i] != NULL)
    {
      tab_env[i] = tab_env[i + 1];
      i = i + 1;
    }
  tab_env[i] = NULL;
  *env = tab_env;
  return (0);
}
