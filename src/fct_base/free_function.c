/*
** free_functions.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Thu Jan 19 23:12:32 2017 Thomas BLENEAU
** Last update Sun Jan 22 13:05:26 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

void	free_tab_function(char **tab)
{
  int	i;

  i = -1;
  if (tab != NULL)
    {
      while (tab[++i] != NULL)
	free(tab[i]);
      free(tab);
    }
}
