/*
** command_found.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Fri Jan 20 17:19:35 2017 Thomas BLENEAU
** Last update Sun Jan 22 14:49:00 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

int	check_str(char *str)
{
  int	i;
  char	**tab;

  i = -1;
  tab = str_to_wordtab(str);
  while (tab[++i] != NULL)
    {
      if ((my_strcmp(tab[i], "env") == 0) || (my_strcmp(tab[i], "exit") == 0)
	  || (my_strcmp(tab[i], "unsetenv") == 0) || (my_strcmp(tab[i], "setenv") == 0)
	  || (my_strcmp(tab[i], "cd") == 0))
	{
	  free_tab_function(tab);
	  return (1);
	}
    }
  free_tab_function(tab);
  return (0);
}

int	check_command(char ***tab_env, char **path, char *str)
{
  char	*string;
  char	**tab;

  if (str == NULL || str[0] == '\0')
    return (0);
  tab = str_to_wordtab(str);
  if (my_put_color(str) == 0)
    return (0);
  else if (access(str, X_OK) == 0)
    program_process(tab_env, tab, str);
  else
    {
      string = check_file_exist(path, tab[0]);
      if (string == 0)
	{
	  write(2, tab[0], my_strlen(tab[0]));
	  write(2, ": Command not found.\n", 21);
	}
      else if (string != 0)
	program_process(tab_env, tab, string);
    }
  free_tab_function(tab);
  return (0);
}
