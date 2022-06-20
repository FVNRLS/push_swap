/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_args.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmazurit <rmazurit@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/10 12:40:30 by rmazurit          #+#    #+#             */
/*   Updated: 2022/06/20 14:56:00 by rmazurit         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	ft_process_raw(int argc, char **argv, t_list **stack, bool *error)
{
	int i;
	int	val;
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
		error = true;
	if (ft_input_invalid(error) == true)
		return (false);
	if (ft_list_size(*stack) == 1)
		return (false);
	return (true);
}
