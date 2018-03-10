/*
** exit_function.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Mon Jan 16 18:13:05 2017 Thomas BLENEAU
** Last update Sat Jan 21 01:24:40 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

void	exit_function(char **tab, char ***tab_env, char *str)
{
  int	status;

  if (tab[1] != NULL)
    {
      if ((my_str_isnum(tab[1]) == 0) && (tab[2] == NULL))
	{
	  status = my_getnbr(tab[1]);
	  free_tab_function(tab);
	  free_tab_function(*tab_env);
	  if (str != NULL)
	    free(str);
	  write(1, "exit\n", 5);
	  exit(status);
	}
      else
	{
	  write(2, "exit: Expression Syntax.\n", 25);
	  return ;
	}
    }
  free_tab_function(tab);
  free_tab_function(*tab_env);
  if (str != NULL)
    free(str);
  exit(0);
}
