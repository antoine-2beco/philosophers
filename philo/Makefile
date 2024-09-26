# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 13:43:54 by ade-beco          #+#    #+#              #
#    Updated: 2024/09/26 11:33:55 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILO		=		philo

SRC_PATH	=		./src/
SRCS 		=		philo.c init.c utils.c

OBJECTS		=		$(SRCS:.c=.o)

CC			=		cc
INC			=		-I $(PHILO).h 
CFLAGS		=		-Wall -Wextra -Werror -g

all: 		$(OBJECTS) $(PHILO)

%.o:		%.c
					@$(CC) $(CFLAGS) -c $(INC) $< -o $(<:c=o)

$(PHILO):	$(OBJECTS)
					@echo "Compiling and Creating Philo..."
					@cc $(CFLAGS) $(INC) -o $(PHILO) $(OBJECTS)
					@echo "OK !"

clean:
					@echo "Cleaning Philo Objects..."
					@rm -f $(OBJECTS)
					@echo "OK !"

fclean:			clean
					@echo "Cleaning Philo..."
					@rm -f $(PHILO)
					@echo "OK !"

re:			fclean all

.PHONY:		all clean fclean re
