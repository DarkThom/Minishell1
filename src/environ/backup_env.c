/*
** backup_env.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Tue Jan 17 22:19:48 2017 Thomas BLENEAU
** Last update Sat Jan 21 21:53:27 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

char		**backup_env(char **env)
{
  t_var_env	inc;

  inc.i = -1;
  if (env == NULL || env[0] == NULL)
    {
      inc.tab_env = NULL;
      return (inc.tab_env);
    }
  if ((inc.tab_env = malloc(sizeof(char *) * (my_tablen(env) + 1))) == NULL)
    return (NULL);
  while (env[++inc.i] != NULL)
    {
      inc.j = 0;
      inc.size = my_strlen(env[inc.i]);
      if ((inc.tab_env[inc.i] = malloc(sizeof(char) * (inc.size + 1))) == NULL)
	return (NULL);
      while (env[inc.i][inc.j] != '\0')
	{
	  inc.tab_env[inc.i][inc.j] = env[inc.i][inc.j];
	  inc.j = inc.j + 1;
	}
      inc.tab_env[inc.i][inc.j] = '\0';
    }
  inc.tab_env[inc.i] = NULL;
  return (inc.tab_env);
}
