/*
** env.h for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Wed Jan 18 22:51:11 2017 Thomas BLENEAU
** Last update Sun Jan 22 00:27:26 2017 Thomas BLENEAU
*/

#ifndef ENV_H_
# define ENV_H_

/*
** Déclaration de la strucutre env
*/

typedef struct  s_var_env
{
  int           i;
  int		j;
  int		size;
  char		*key;
  char		**tab_env;
  char		**env_bis;
}               t_var_env;

/*
** Prototypes de fonction setenv, getenv, unsetenv
*/

int     my_unsetenv(char ***env, char *name);
int     my_setenv(char ***env, char *name, char *value);
char    *my_getenv(char *str, char **env);

/*
** Prototypes de fonctions
*/

char    **env_file(char **env);
char    **backup_env(char **env);
char    *env_access(char **env, char *str, int *i);
char    *find_key_name(char **tab_env, char *name);
char	*check_file_exist(char **env, char *str);
int	find_key_position(char **tab_env, char *name);
int     check_key(char *str);
int     check_str(char *str);
int	setenv_error(char **tab, char ***tab_env);
int	unsetenv_error(char **tab, char ***tab_env);
void	env_error(char **tab, char ***tab_env);
void    display_env(char **env);

#endif /* !ENV_H_ */
