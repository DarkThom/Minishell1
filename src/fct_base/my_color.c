/*
** my_color.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Sun Jan 22 00:48:25 2017 Thomas BLENEAU
** Last update Sun Jan 22 01:38:55 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

int	my_put_color(char *str)
{
  if (my_strcmp("red", str) == 0)
    {
      write(1, "\e[31m", 6);
      return (0);
    }
  else if (my_strcmp("green", str) == 0)
    {
      write(1, "\e[32m", 6);
      return (0);
    }
  else if (my_strcmp("yellow", str) == 0)
    {
      write(1, "\e[33m", 6);
      return (0);
    }
  else if (my_strcmp("blue", str) == 0)
    {
      write(1, "\e[34m", 6);
      return (0);
    }
  return (1);
}
