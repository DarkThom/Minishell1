/*
** env_file.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Mon Jan 16 18:03:30 2017 Thomas BLENEAU
** Last update Sat Jan 21 02:08:11 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

char	**env_file(char **env)
{
  int	i;
  int	j;
  char	*str;
  char	**tab_env;

  i = -1;
  j = -1;
  while (env != NULL && env[++i] != NULL)
    {
      if (env[i][0] == 'P' && env[i][1] == 'A'
	  && env[i][2] == 'T' && env[i][3] == 'H'
	  && env[i][4] == '=')
	{
	  str = str_copy(env[i]);
	  tab_env = path_to_wordtab(str);
	  if (str != NULL)
	    free(str);
	}
    }
  while (tab_env != NULL && tab_env[++j] != NULL)
    tab_env[j] = tab_env[j + 1];
  tab_env[j] = NULL;
  return (tab_env);
}

char	*env_access(char **path, char *str, int *i)
{
  char	*string;

  string = my_str_concatenate(path[*i], str, '/');
  return (string);
}

char	*check_file_exist(char **path, char *str)
{
  int	i;
  char	**tab;
  char	*string;

  i = 0;
  tab = str_to_wordtab(str);
  while (path[i] != NULL)
    {
      string = env_access(path, tab[0], &i);
      if (access(string, X_OK) == 0)
	{
	  free_tab_function(tab);
	  return (string);
	}
      else
	free(string);
      i = i + 1;
    }
  return (0);
}
