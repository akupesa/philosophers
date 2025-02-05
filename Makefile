# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akupesa <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/12 15:11:28 by akupesa           #+#    #+#              #
#    Updated: 2025/01/13 09:56:15 by akupesa          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
FLAGS = -Wall -Werror -Wextra -g
OBJDIR = obj
HEADER := philo.h
SRC = 	src/main.c \
		src/dead.c \
		src/time.c \
		src/init.c \
		src/forks.c \
		src/utils.c \
		src/threads.c \
		src/thinking.c \
		src/philo_thread.c \
		src/close_checker.c \
		src/fill_functions.c \
		src/init_arguments.c \
		src/print_state_change.c \


OBJFILES = $(SRC:%.c=$(OBJDIR)/%.o)

NAME = philo

all: setup $(NAME)

$(NAME): $(OBJFILES) ${HEADER}
	$(CC) $(FLAGS) $(SRC) -o $(NAME) -pthread

$(OBJDIR)/%.o: %.c
	$(CC) $(FLAGS) -c $< -o $@ -pthread

setup:
	@mkdir -p $(OBJDIR)/src

clean:
	rm -f $(OBJFILES)
	rm -r -f obj/

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean setup re
