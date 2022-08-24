# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 17:29:32 by rmazurit          #+#    #+#              #
#    Updated: 2022/06/22 13:49:41 by rmazurit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 		= 	push_swap
BONUS_NAME	=	checker

CC 		= 	cc

FLAGS		= 	-Wall -Wextra -Werror

PUSH_SWAP	=	push_swap.c 						\

SRC 		= 	./argument_processors/argument_managers.c		\
			./argument_processors/error_managers.c			\
			./argument_processors/nodes_managers.c			\
			./finders_and_counters/counters.c			\
			./finders_and_counters/key_number_finder.c		\
			./finders_and_counters/limit_finders.c			\
			./finders_and_counters/position_finders.c		\
			./finders_and_counters/stack_checkers.c			\
			./instructions/push_and_swap.c				\
			./instructions/rotate.c					\
			./instructions/reverse_rotate.c				\
			./sorters/big_stack_sorter.c				\
			./sorters/small_stack_sorter.c				\
			./sorters/stack_b_sorter.c				\
			./tools/ft_atol.c					\
			./tools/ft_is_digit.c					\
			./tools/ft_split.c					\
			./tools/ft_strlen.c					\
	
CHECKER		=	checker.c						\

BONUS_SRC	=	./bonus/tools.c						\
			./bonus/checker_instructions/checker_push_and_swap.c	\
			./bonus/checker_instructions/checker_reverse_rotate.c	\
			./bonus/checker_instructions/checker_rotate.c		\

OBJ 		= 	${PUSH_SWAP:.c=.o} ${SRC:.c=.o}

BONUS_OBJ	= 	${CHECKER:.c=.o} ${SRC:.c=.o} ${BONUS_SRC:.c=.o}

${NAME}: ${OBJ}
	${CC} ${FLAGS} ${OBJ} -o ${NAME}

${BONUS_NAME}: ${BONUS_OBJ}
	${CC} ${FLAGS} ${BONUS_OBJ} -o ${BONUS_NAME}

all: ${NAME}

bonus: ${BONUS_NAME}

clean:
	rm -f ${OBJ} ${BONUS_OBJ}

fclean: clean
	rm -f ${NAME} ${BONUS_NAME}

re: fclean all


.PHONY: all clean fclean re bonus
