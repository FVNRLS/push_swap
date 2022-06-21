# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 17:29:32 by rmazurit          #+#    #+#              #
#    Updated: 2022/06/21 20:08:26 by rmazurit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 		push_swap.a

CC 			= 		gcc

FLAGS		= 		-Wall -Wextra -Werror

SRC 		= 		push_swap.c 											\
					./argument_processors/nodes_managers.c					\
					./argument_processors/error_managers.c					\
					./argument_processors/nodes_managers.c					\
					./finders_and_counters/counters.c						\
					./finders_and_counters/key_number_finder.c				\
					./finders_and_counters/limit_finders.c					\
					./finders_and_counters/position_finders.c				\
					./finders_and_counters/stack_checkers.c					\
					./instructions/push_and_swap.c							\
					./instructions/rotate.c									\
					./instructions/reverse_rotate.c							\
					







				
BONUS_SRC	=		./bonus/tools.c											\
					./bonus/checker_instructions/checker_push_and_swap.c	\
					./bonus/checker_instructions/checker_reverse_rotate.c	\
					./bonus/checker_instructions/checker_rotate.c			\
all: $(NAME)

$(NAME): *.c
	make -C ./libft
	cp ./libft/libft.a $(NAME)
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) *.o

clean:
	rm -f ./libft/*.o
	rm -f *.o

fclean: clean
	rm -f ./libft/libft.a
	rm -f ./libft/*.o
	rm -f $(NAME)

re: fclean $(NAME)

bonus: all

.PHONY: all clean fclean re bonus
