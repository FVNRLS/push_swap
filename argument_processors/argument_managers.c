/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_managers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:40:30 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/23 10:35:21 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/*
	Process raw arguments (without quotation marks).
	For each argument:
		1) Create a new node.
		2) Convert every argument into an long with atol()
		3) Assign the number to the new node.
		4) Add the new node to the end of the stack.
*/
static void	ft_process_raw(int argc, char **argv, t_list **stack, bool *error)
{
	int		i;
	int		val;
	t_list	*tmp;

	tmp = NULL;
	i = 1;
	while (i < argc)
	{
		val = ft_atol(argv[i], error);
		tmp = ft_new_node(val);
		ft_add_back(stack, tmp);
		i++;
	}
}

/*
	Free the allocated memory from the split function.
	Due to the split is a double-pointer (2D array), memory should be freed
	for each index of the split result, as well as for the split itself.
*/
static void	ft_free_split(char **split)
{
	int		i;

	i = 0;
	while (split[i] != NULL)
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
	split = NULL;
}

/*
	Process arguments, included between quotation marks (so argc is 2).
	Firstly split the input arguments with ft_split().
	For each argument:
		1) Create a new node.
		2) Convert every argument into an long with atol()
		3) Assign the number to the new node.
		4) Add the new node to the end of the stack.
*/
static void	ft_process_split(char **argv, t_list **stack, bool *error)
{
	t_list	*tmp;
	char	**split;
	int		val;
	int		i;

	tmp = NULL;
	split = ft_split(argv[1], DELIMETER);
	i = 0;
	while (split[i] != NULL)
	{
		val = ft_atol(split[i], error);
		tmp = ft_new_node(val);
		ft_add_back(stack, tmp);
		i++;
	}
	ft_free_split(split);
}

/*
	Create STACK A, depending on the provided arguments and their number.
	Don't create STACK A, if:
		1) no arguments provided.
		2) only 1 argument provided (and the arg is not included between " ").
	Check if the input is invalid. Return error message, if:
		1) Duplicates were found.
		2) Input is not a digit (invalid characters).
		3) input overflows the range of type int (arg > INT_MAX or arg < INT_MIN).
	Return false in case, when errors were found. Otherwise - return true.
*/
bool	ft_create_stack(int argc, char **argv, t_list **stack)
{
	bool	error;

	error = false;
	if (argc == 2)
		ft_process_split(argv, stack, &error);
	else if (argc > 2)
		ft_process_raw(argc, argv, stack, &error);
	else if (argc == 1)
		return (false);
	if (argc == 2 && ft_list_size(*stack) == 0)
		ft_check_invalid_chars(argv[1], &error);
	if (ft_duplicates_found(*stack) == true)
	{
		error = true;
		ft_delete_stack(stack);
		ft_error_message(error);
	}
	if (ft_list_size(*stack) == 1)
		return (false);
	return (true);
}
