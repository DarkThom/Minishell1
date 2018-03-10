/*
** str_to_wordtab.c for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Thu Jan 19 01:45:15 2017 Thomas BLENEAU
** Last update Sun Jan 22 13:07:01 2017 Thomas BLENEAU
*/

#include "minishell1.h"
#include "str_to_wordtab.h"
#include "get_next_line.h"
#include "env.h"
#include "my.h"

int		str_isnumalpha(char k)
{
  if (k == ' ')
    return (1);
  return (0);
}

int		nbr_words(char *str)
{
  int		k;
  int		word;

  k = 0;
  word = 0;
  while (str[k] != '\0')
    {
      while (str_isnumalpha(str[k]) != 0 && str[k] != '\0')
	k = k + 1;
      if (str[k] != '\0')
	word = word + 1;
      while (str_isnumalpha(str[k]) == 0 && str[k] != '\0')
	k = k + 1;
    }
  return (word);
}

char		**str_to_wordtab(char *str)
{
  char          **tab;
  t_parse       inc;

  inc.i = 0;
  inc.j = 0;
  inc.k = 0;
  inc.word = nbr_words(str);
  if (((tab = malloc(sizeof(char *) * (inc.word + 1))) == NULL)
      || (str == NULL))
    return (NULL);
  while (inc.k < inc.word)
    {
      inc.j = 0;
      if ((tab[inc.k] = malloc(sizeof(char) * (my_strlen(str) + 1))) == NULL)
	return (NULL);
      while (str_isnumalpha(str[inc.i]) != 0 && str[inc.i] != '\0')
	inc.i = inc.i + 1;
      while (str_isnumalpha(str[inc.i]) == 0 && str[inc.i] != '\0')
	tab[inc.k][inc.j++] = str[inc.i++];
      tab[inc.k][inc.j] = '\0';
      inc.k = inc.k + 1;
    }
  tab[inc.k] = NULL;
  return (tab);
}
