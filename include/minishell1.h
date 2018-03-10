/*
** minishell1.h for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
**
** Made by Thomas BLENEAU
** Login   <BLENEA_T@epitech.net>
**
** Started on  Wed Jan 11 19:41:18 2017 Thomas BLENEAU
** Last update Sun Jan 22 15:57:10 2017 Thomas BLENEAU
*/

#ifndef MINISHELL_1_H
# define MINISHELL_1_H

/*
** Include de la LibC
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <sys/resource.h>
#include <sys/time.h>
#include <signal.h>

/*
** Prototypes de fonctions
*/

int     builtins_process(char *str, char ***tab_env);
int	shell_program(char ***tab_env);
int	program_process(char ***tab_env, char **tab, char *exec);
int	cd_function(char **tab);
int	cd_error(char ***tab_env);
int	check_command(char ***tab_env, char **path, char *str);
int	my_put_color(char *str);
void	ctrl_c_function(int sig);
void	ctrl_d_function(char ***tab_env);
void	exit_function(char **tab, char ***tab_env, char *str);
void	print_prompt();
void	command_found(char *str);
void	free_tab_function(char **tab);


#endif /* !MINISHELL_1_H */
