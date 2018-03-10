/*
** main.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Wed Jan 11 19:41:03 2017 Thomas BLENEAU
** Last update Sun Jan 22 11:32:53 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

int	main(int ac, char **av, char **env)
{
  char	**tab_env;

  (void) ac;
  (void) av;
  if ((tab_env = backup_env(env)) == NULL)
    return (84);
  shell_program(&tab_env);
  free_tab_function(tab_env);
  return (0);
}
