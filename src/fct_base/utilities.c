/*
** utilities.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Tue Jan 17 08:20:49 2017 Thomas BLENEAU
** Last update Sat Jan 21 01:55:39 2017 Thomas BLENEAU
*/

#include "../../include/minishell1.h"
#include "../../include/str_to_wordtab.h"
#include "../../include/get_next_line.h"
#include "../../include/env.h"
#include "../../include/my.h"

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0')
    i = i + 1;
  return (s1[i] - s2[i]);
}

int	my_strncmp(char *s1, char *s2, int n)
{
  int	i;

  i = 0;
  while (s1[i] != '\0' && s2[i] != '\0' && i < n)
    {
      if (s1[i] == s2[i])
	i = i + 1;
      else
	return (s1[i] - s2[i]);
    }
  return (0);
}

int	my_str_isnum(char *str)
{
  int   i;

  i = -1;
  while (str[++i] != '\0')
    {
      if (str[i] < '0' || str[i] > '9')
	return (1);
    }
  return (0);
}

char	*my_strncpy(char *dest, char *src, int n)
{
  int	i;

  i = 0;
  while (src[i] && i < n)
    {
      dest[i] = src[i];
      i = i + 1;
    }
  dest[i] = '\0';
  return (dest);
}

char	*str_copy(char *str)
{
  int   i;
  char  *string;

  i = -1;
  if ((string = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  while (str[++i] != '\0')
    string[i] = str[i];
  string[i] = '\0';
  return (string);
}
