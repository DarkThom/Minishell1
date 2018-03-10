/*
** print_prompt.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Thu Jan 19 09:55:39 2017 Thomas BLENEAU
** Last update Sun Jan 22 11:30:53 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

void	print_prompt()
{
  write(1, "$> ", 3);
}

void	print_welcome()
{
  write(1, "\e[31m", 6);
  write(1, "Welcome in Minishell\n", 21);
  write(1, "\e[39m", 6);
}
