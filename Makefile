# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/14 17:29:32 by rmazurit          #+#    #+#              #
#    Updated: 2022/05/27 11:16:15 by rmazurit         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 		push_swap.a

CC 		= 		gcc

FLAGS	= 		-Wall -Wextra -Werror

SRC 	= 		push_swap.c \
				

				
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
