/*
** shell_progam.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Thu Jan 19 09:53:21 2017 Thomas BLENEAU
** Last update Sun Jan 22 14:42:38 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

int	shell_program(char ***tab_env)
{
  char	*str;
  char	**path;
  int	boolean;

  str = NULL;
  signal(SIGINT, ctrl_c_function);
  path = env_file(*tab_env);
  while ((boolean = 1) == 1)
    {
      print_prompt();
      str = get_next_line(0);
      if (str != NULL)
	str = clean_str(str);
      else
	ctrl_d_function(tab_env);
      if (check_str(str) == 1)
	builtins_process(str, tab_env);
      else
	check_command(tab_env, path, str);
    }
  return (0);
}
