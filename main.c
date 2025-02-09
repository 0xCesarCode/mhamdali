/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:43:17 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/09 13:33:52 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	split_argument(char *str, t_node **stack_a)
{
	char	**split;
	int		i;

	i = 0;
	split = NULL;
	if (*str == '\0')
		exit_error(0, *stack_a, split);
	split = ft_split(str, ' ');
	if (!split)
		return ;
	while (split[i])
	{
		check_valid_number(split[i], *stack_a, split);
		push_back(stack_a, ft_atoi(split[i], *stack_a, split));
		i++;
	}
	clean_pointer(split);
	if (i == 0)
		exit_error(0, *stack_a, split);
}

int	main(int ac, char **av)
{
	int		a;
	t_node	*stack_a;
	t_node	*stack_b;

	a = 1;
	stack_a = NULL;
	stack_b = NULL;
	if (ac < 2)
		return (0);
	while (av[a])
	{
		split_argument(av[a], &stack_a);
		a++;
	}
	check_duplicate(stack_a);
	check_sorted_range(&stack_a, &stack_b);
	free_stack(stack_a);
	free_stack(stack_b);
	return (0);
}
