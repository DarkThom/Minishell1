/*
** signal_fonction.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Thu Jan 19 12:53:53 2017 Thomas BLENEAU
** Last update Sat Jan 21 01:55:05 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

void	ctrl_c_function(int sig)
{
  (void) sig;
  write(1, "\n$> ", 4);
}

void	ctrl_d_function(char ***tab_env)
{
  free_tab_function(*tab_env);
  write(1, "exit\n", 5);
  exit(0);
}
