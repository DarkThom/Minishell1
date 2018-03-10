/*
** display_env.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Tue Jan 17 22:00:35 2017 Thomas BLENEAU
** Last update Sat Jan 21 01:56:32 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

void	display_env(char **env)
{
  int	i;

  i = -1;
  while (env[++i] != NULL)
    {
      write(1, env[i], my_strlen(env[i]));
      write(1, "\n", 1);
    }
}
