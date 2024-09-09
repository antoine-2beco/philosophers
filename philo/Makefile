# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ade-beco <ade-beco@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/09/09 13:43:54 by ade-beco          #+#    #+#              #
#    Updated: 2024/09/09 13:49:59 by ade-beco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PHILO		=		philo

SRC_PATH	=		./src/
SRCS 		=		philo.c

OBJECTS		=		$(SRCS:.c=.o)

INC			=		-I $(PHILO).h 
CFLAGS		=		-Wall -Wextra -Werror

all: 		$(OBJECTS) $(PHILO)

%.o:		%.c
					@cc $(CFLAGS) -c $< -o $(<:c=o)

$(PHILO):	$(OBJECTS)
					@echo "Compiling and Creating Philo..."
					@ar -rcs $(PHILO) $(OBJECTS)
					@cc $(PHILO) $(CFLAGS)$(INC) -o $(PHILO)
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
