/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:40:30 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/10 19:18:14 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_process_raw_args(int argc, char **argv, t_list **stack, bool *error_flag)
{
	int i;
	int	val;
	t_list	*tmp;

	tmp = NULL;
	i = 1;
	while (i < argc)
	{
		val = ft_atoi(argv[i], error_flag);
		tmp = ft_new_node(val);
		ft_add_back(stack, tmp);
		i++;
	}
}

void	ft_process_split_args(char **argv, t_list **stack, bool *error_flag)
{
	t_list	*tmp;
	char	**split;
	int		val;
	int		i;

	tmp = NULL;
	*stack = NULL;
	split = ft_split(argv[1], DELIMETER);
	i = 0;
	while (split[i] != NULL)
	{
		val = ft_atoi(split[i], error_flag);		
		tmp = ft_new_node(val);
		ft_add_back(stack, tmp);
		i++;
	}
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

bool	ft_create_stack(int argc, char **argv, t_list **stack)
{
	bool	error_flag;
	
	error_flag = false;
	if (argc > 2)
		ft_process_raw_args(argc, argv, stack, &error_flag);
	else if (argc == 2)
		ft_process_split_args(argv, stack, &error_flag);
	else
	{
		write(1, "Input some arguments!\n", 22);
		return (false);
	}
	if (ft_input_invalid(error_flag) == true)
		return (false);
	return (true);
}


bool	ft_input_invalid(bool error_flag)
{
	if (error_flag == true)
	{
		write (1, "\nError! Invalid arguments found!\n\n", 37);
		return (true);
	}
	return (false);
}

bool	ft_duplicates_found(t_list *stack)
{
	t_list	*pos;
	t_list	*next_node;
	
	pos = stack;
	next_node = pos;
	while (pos != NULL)
	{
		while (next_node->next != NULL)
		{
			next_node = next_node->next;
			if (pos->nbr == next_node->nbr)
			{
				write(1, "\nError! Duplicated arguments found!\n\n", 38);
				return (true);
			}
		}
		next_node = pos->next;
		pos = pos->next;
	}
	return (false);
}