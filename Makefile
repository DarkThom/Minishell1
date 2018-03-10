##
## Makefile for  in /home/BLENEA_T/Projects/PSU/PSU_2016_minishell1
## 
## Made by Thomas BLENEAU
## Login   <BLENEA_T@epitech.net>
## 
## Started on  Wed Jan 11 19:40:30 2017 Thomas BLENEAU
## Last update Sun Jan 22 20:50:12 2017 Thomas BLENEAU
##

RM	= rm -f

CC	= gcc

CFLAGS	+= -W -Wall -Wextra -g
CFLAGS	+= -I ./include/

NAME	= mysh

SRCS	= main.c \
	  ./src/builtins/cd_function.c \
	  ./src/builtins/exit_function.c \
	  ./src/builtins/my_getenv.c \
	  ./src/builtins/my_setenv.c \
	  ./src/builtins/my_unsetenv.c \
	  ./src/clean_str.c \
	  ./src/command_found.c \
	  ./src/environ/backup_env.c \
	  ./src/environ/display_env.c \
	  ./src/environ/env_error.c \
	  ./src/environ/env_file.c \
	  ./src/environ/program_process.c \
	  ./src/environ/shell_program.c \
	  ./src/fct_base/free_function.c \
	  ./src/fct_base/get_next_line.c \
	  ./src/fct_base/my_color.c \
	  ./src/fct_base/my_getnbr.c \
	  ./src/fct_base/my_str_concatenate.c \
	  ./src/fct_base/parsing_file.c \
	  ./src/fct_base/str_to_wordtab.c \
	  ./src/fct_base/utilities.c \
	  ./src/find_key_name.c \
	  ./src/print_prompt.c \
	  ./src/signal_function.c \

OBJS	= $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(OBJS)

all:	$(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
