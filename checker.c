/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 13:09:07 by rmeuth            #+#    #+#             */
/*   Updated: 2022/06/20 16:41:27 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

#define EXIT_ERROR 2

static int	error_handler(void)
{
	write(2, "Error\n", 6);
	return (EXIT_FAILURE);
}

static int	execute_operation(t_list *data, char *operation)
{
	if (ft_strncmp(operation, "pa\n", 3) == 0)
		pa(data);
	else if (ft_strncmp(operation, "pb\n", 3) == 0)
		pb(data);
	else if (ft_strncmp(operation, "sa\n", 3) == 0)
		sa(data);
	else if (ft_strncmp(operation, "sb\n", 3) == 0)
		sb(data);
	else if (ft_strncmp(operation, "ss\n", 3) == 0)
		ss(data);
	else if (ft_strncmp(operation, "ra\n", 3) == 0)
		ra(data);
	else if (ft_strncmp(operation, "rb\n", 3) == 0)
		rb(data);
	else if (ft_strncmp(operation, "rr\n", 3) == 0)
		rr(data);
	else if (ft_strncmp(operation, "rra\n", 4) == 0)
		rra(data);
	else if (ft_strncmp(operation, "rrb\n", 4) == 0)
		rrb(data);
	else if (ft_strncmp(operation, "rrr\n", 4) == 0)
		rrr(data);
	else
		return (EXIT_ERROR);
	return (EXIT_SUCCESS);
}

static int	validate_instructions(t_list *data)
{
	char	operation[4];
	int		i;

	data->log = false;
	i = 0;
	while (i < 4 && read(STDIN_FILENO, &operation[i], 1) > 0)
	{
		if (operation[i++] != '\n')
			continue ;
		if (execute_operation(data, operation) == EXIT_ERROR)
			return (EXIT_ERROR);
		i = 0;
	}
	if (i > 3)
	{
		while (read(STDIN_FILENO, &operation, 1) > 0 && *operation != '\n')
			continue ;
		return (EXIT_ERROR);
	}
	if (!(data->stack_a[0] == 0 && data->len_a == data->n && data->len_b == 0))
		return (EXIT_FAILURE);
	if (!array_is_sorted(data->stack_a, data->n))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	main(int argc, char *argv[])
{
	int		n;
	int		*array;
	t_list	*data;
	int		result;

	if (argc < 2)
		return (0);
	n = valid_input(argv);
	if (n == -1)
		return (error_handler());
	array = split_input(argv, n);
	if (array == NULL)
		return (error_handler());
	if (simplify_array(array, n) == NULL)
		return (error_handler());
	data = init_data_struct(array, n);
	result = validate_instructions(data);
	free_data_struct(data);
	if (result == EXIT_ERROR)
		return (error_handler());
	else if (result == EXIT_SUCCESS)
		write(1, "OK\n", 3);
	else if (result == EXIT_FAILURE)
		write(1, "KO\n", 3);
	return (0);
}
