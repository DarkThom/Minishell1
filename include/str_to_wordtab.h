/*
** str_to_wordtab.h for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Wed Jan 18 22:48:57 2017 Thomas BLENEAU
** Last update Thu Jan 19 01:49:31 2017 Thomas BLENEAU
*/

#ifndef STR_TO_WORDTAB_
# define STR_TO_WORDTAB_

/*
** Déclaration de la strucutre str_to_wordtab
*/

typedef struct  s_parse
{
  int           i;
  int           j;
  int           k;
  int           word;
}               t_parse;

/*
** Prototypes de fonctions str_to_wordtab
*/

char    **str_to_wordtab(char *str);
char	**path_to_wordtab(char *str);
int     str_isnumalpha(char k);
int	path_isnumalpha(char k);
int     nbr_words(char *str);
int	path_nbr_words(char *str);

#endif /* !STR_TO_WORDTAB_ */
