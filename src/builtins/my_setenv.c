/*
** my_setenv.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Tue Jan 17 20:48:30 2017 Thomas BLENEAU
** Last update Sun Jan 22 21:15:27 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

void		replace_key_value(char ***env, char **tab_env,
				  char *name, char *value)
{
  int		i;
  int		k;
  int		j;

  k = 0;
  j = my_strlen(name) + 1;
  i = find_key_position(tab_env, name);
  while (value != NULL && tab_env[i] != NULL
	 && tab_env[i][j] != '\0' && value[k] != '\0' )
    {
      tab_env[i][j] = value[k];
      k = k + 1;
      j = j + 1;
    }
  tab_env[i][j] = '\0';
  *env = tab_env;
}

void		create_key_name(char ***env, char **tab_env,
				char **env_bis, char *name, char *value)
{
  int		i;

  if (value != NULL)
    {
      i = -1;
      while (env_bis[++i] != NULL)
	tab_env[i] = env_bis[i];
      tab_env[i] = my_str_concatenate(name, value, '=');
      tab_env[i + 1] = NULL;
      *env = tab_env;
    }
  else
    {
      i = -1;
      while (env_bis[++i] != NULL)
	tab_env[i] = env_bis[i];
      tab_env[i] = my_str_concatenate(name, "", '=');
      tab_env[i + 1] = NULL;
      *env = tab_env;
    }
}

int		my_setenv(char ***env, char *name, char *value)
{
  t_var_env	inc;

  inc.i = -1;
  if (name == NULL || env == NULL || (check_key(name)))
    return (-1);
  inc.env_bis = *env;
  while (inc.env_bis[++inc.i]);
  if ((inc.tab_env = malloc(sizeof(char *) * (inc.i + 2))) == NULL)
    return (-1);
  if ((inc.key = find_key_name(inc.env_bis, name)) == NULL)
    create_key_name(env, inc.tab_env, inc.env_bis, name, value);
  else
      replace_key_value(env, inc.env_bis, name, value);
  return (0);
}
