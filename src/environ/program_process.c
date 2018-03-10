/*
** program_process.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Fri Jan 20 15:07:14 2017 Thomas BLENEAU
** Last update Sun Jan 22 20:51:46 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

int	interpret_status(int status)
{
  if (status == 0)
    return (0);
  else if (status == 139)
    write(2, "Segmentation fault (core dumped)\n", 33);
  else if (status == 136)
    write(2, "Floating point exception (core dumped)\n", 39);
  else if (status == 134)
    write(2, "Aborted (core dumped)\n", 22);
  return (status);
}

int	builtins_process(char *str, char ***tab_env)
{
  char	**tab;

  tab = str_to_wordtab(str);
  if (my_strcmp(tab[0], "env") == 0)
    env_error(tab, tab_env);
  else if (my_strcmp(tab[0], "exit") == 0)
    exit_function(tab, tab_env, str);
  else if (my_strcmp(tab[0], "setenv") == 0)
    setenv_error(tab, tab_env);
  else if (my_strcmp(tab[0], "unsetenv") == 0)
    unsetenv_error(tab, tab_env);
  else if (my_strcmp(tab[0], "cd") == 0)
    {
      if ((cd_function(tab)) == 1)
	cd_error(tab_env);
    }
  return (0);
}

int	program_process(char ***tab_env, char **tab, char *exec)
{
  pid_t	pid;
  int	status;
  char	**env_bis;

  status = 0;
  env_bis = *tab_env;
  if ((pid = fork()) == -1)
    return (-1);
  else if (pid == 0)
    execve(exec, tab, env_bis);
  else
    wait(&status);
  interpret_status(status);
  return (status);
}
