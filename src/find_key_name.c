/*
** find_key_name.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Tue Jan 17 22:10:18 2017 Thomas BLENEAU
** Last update Sun Jan 22 16:29:01 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

int	my_tablen(char **env)
{
  int   i;

  i = -1;
  while (env[++i] != NULL);
  return (i);
}

int	check_key(char *str)
{
  int	i;
  char	s[] = "setenv: Variable name must contain alphanumeric characters.\n";

  i = -1;
  while (str[++i] != '\0')
    if (str[i] == '=')
      {
	write(2, s, my_strlen(s));
	return (1);
      }
  return (0);
}

char	*find_key_name(char **tab_env, char *name)
{
  int	i;

  i = 0;
  while (tab_env != NULL && tab_env[i] != NULL)
    {
      if (my_strncmp(name, tab_env[i], my_strlen(name)) == 0)
	return (name);
      i = i + 1;
    }
  return (0);
}

int	find_key_position(char **tab_env, char *name)
{
  int	i;

  i = 0;
  while (tab_env != NULL && tab_env[i] != NULL)
    {
      if (my_strncmp(name, tab_env[i], my_strlen(name)) == 0)
	return (i);
      i = i + 1;
    }
  return (0);
}
