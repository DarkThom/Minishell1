/*
** clean_str.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Thu Jan 19 21:56:46 2017 Thomas BLENEAU
** Last update Sun Jan 22 21:18:54 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

char	*clean_str(char *str)
{
  int	j;
  int	i;
  char	*string;

  if (str == NULL)
    return (NULL);
  if ((string = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
    return (NULL);
  i = 0;
  j = 0;
  while (str != NULL && str[i] != '\0')
    {
      if ((str[i] == '\t' || str[i] == ' ') && str[i] != '\0')
	{
	  while ((str[i] == '\t' || str[i] == ' ') && str[i] != '\0')
	    i = i + 1;
	  if (str[i] != '\0' && j > 0)
	    string[j++] = ' ';
	}
      string[j] = str[i];
      i = i + 1;
      j = j + 1;
    }
  string[j] = '\0';
  return (string);
}
