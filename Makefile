# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 17:29:32 by rmazurit          #+#    #+#              #
#    Updated: 2022/06/22 12:07:24 by rmazurit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 		push_swap

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
					./sorters/big_stack_sorter.c							\
					./sorters/small_stack_sorter.c							\
					./sorters/stack_b_sorter.c								\
					./tools/ft_atol.c										\
					./tools/ft_is_digit.c									\
					./tools/ft_split.c										\
					./tools/ft_strlen.c										\
	
BONUS_SRC	=		./bonus/tools.c											\
					./bonus/checker_instructions/checker_push_and_swap.c	\
					./bonus/checker_instructions/checker_reverse_rotate.c	\
					./bonus/checker_instructions/checker_rotate.c			\
all: $(NAME)

$(NAME): *.c
	$(CC) $(FLAGS) -c $(SRC)

clean:
	rm -f *.o

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)

bonus: $(NAME)
	$(NAME): *.c
	$(CC) $(FLAGS) -c $(SRC)
	$(CC) $(FLAGS) -c $(BONUS_SRC)

.PHONY: all clean fclean re bonus
