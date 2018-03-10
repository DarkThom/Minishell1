/*
** cd_function.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Mon Jan 16 18:14:10 2017 Thomas BLENEAU
** Last update Sun Jan 22 16:34:25 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

int	cd_error(char ***tab_env)
{
  char	*str;
  char	*pwd;
  int	size;

  size = 200;
  if (tab_env == NULL)
    return (-1);
  if ((str = malloc(sizeof(char) * (size + 1))) == NULL)
    return (-1);
  if ((pwd = getcwd(str, size)) != NULL)
    my_setenv(tab_env, "OLDPWD", pwd);
  return (0);
}

int	cd_function(char **tab)
{
  if (tab[1] != NULL)
    {
      if (access(tab[1], R_OK) == -1 && tab[2] == NULL)
	{
	  perror(tab[1]);
	  return (0);
	}
      else if (access(tab[1], F_OK) == -1 && tab[2] == NULL)
	{
	  perror(tab[1]);
	  return (0);
	}
      else if (chdir(tab[1]) == -1 && tab[2] == NULL)
	{
	  perror(tab[1]);
	  return (0);
	}
      else if (tab[2] != NULL)
	{
	  write(2, "cd: Too many arguments.\n", 24);
	  return (0);
	}
      return (1);
    }
  return (0);
}
