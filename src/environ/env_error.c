/*
** env_error.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Fri Jan 20 17:59:23 2017 Thomas BLENEAU
** Last update Sun Jan 22 00:27:07 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

int	unsetenv_error(char **tab, char ***tab_env)
{
  int	i;

  i = -1;
  while (tab[++i] != NULL);
  if (i == 1)
    {
      write(2, "unsetenv: Too few arguments.\n", 29);
      return (0);
    }
  else if (i > 2)
    return (0);
  else
    my_unsetenv(tab_env, tab[1]);
  return (0);
}

int	setenv_error(char **tab, char ***tab_env)
{
  int	i;

  i = -1;
  while (tab[++i] != NULL);
  if (i > 3)
    {
      write(2, "setenv: Too many arguments.\n", 28);
      return (0);
    }
  else if (tab[1] == NULL)
    display_env(*tab_env);
  else
    my_setenv(tab_env, tab[1], tab[2]);
  return (0);
}

void	env_error(char **tab, char ***tab_env)
{
  if ((my_strcmp(tab[0], "env") == 0) && tab[1] == NULL)
    display_env(*tab_env);
  else
    {
      write(2, "env: '", 6);
      write(2, tab[1], my_strlen(tab[1]));
      write(2, "': No such file or directory\n", 29);
    }
}
