/*
** my.h for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Fri Jan 20 15:17:30 2017 Thomas BLENEAU
** Last update Sat Jan 21 21:59:21 2017 Thomas BLENEAU
*/

#ifndef MY_H_
# define MY_H_

/*
** Prototypes de fonctions
*/

char    *my_str_concatenate(char *src, char *dest, char c);
char    *my_strncpy(char *src, char *dest, int n);
char    *clean_str(char *str);
char    *str_copy(char *str);
char	**my_tabdup(char **env, char **tab_env);
int     my_strlen(char *str);
int     my_tablen(char **env);
int     my_str_isnum(char *str);
int     my_strcmp(char *s1, char *s2);
int     my_strncmp(char *s1, char *s2, int n);
int     my_getnbr(char *str);

#endif /* !MY_H_ */
