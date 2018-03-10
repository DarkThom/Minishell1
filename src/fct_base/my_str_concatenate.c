/*
** my_str_concatenate.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Thu Jan 19 00:28:44 2017 Thomas BLENEAU
** Last update Sun Jan 22 13:04:04 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

char	*my_str_concatenate(char *src, char *dest, char c)
{
  char  *str;
  int   i;
  int   size;

  i = 0;
  size = my_strlen(src);
  if ((str = malloc(sizeof(char) * (size + my_strlen(dest) + 2))) == NULL)
    return (NULL);
  while (*src != '\0')
    {
      str[i] = *src;
      i = i + 1;
      src = src + 1;
    }
  str[i] = c;
  i = i + 1;
  while (*dest != '\0')
    {
      str[i] = *dest;
      i = i + 1;
      dest = dest + 1;
    }
  str[i] = '\0';
  return (str);
}
