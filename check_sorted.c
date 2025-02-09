/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_sorted.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:03:29 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/09 14:47:40 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	free_stack(t_node *stack)
{
	t_node	*tmp;

	if (!stack)
		return ;
	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

int	check_sorted(t_node *stack)
{
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	sort_three(t_node **stack_a)
{
	int	first;
	int	second;
	int	third;

	first = (*stack_a)->data;
	second = (*stack_a)->next->data;
	third = (*stack_a)->next->next->data;
	if (first > second && second < third && first < third)
		sa(stack_a, 0);
	else if (first > second && second > third)
	{
		sa(stack_a, 0);
		rotate(stack_a, 0);
	}
	else if (first > second && second < third && first > third)
		rotate(stack_a, 0);
	else if (first < second && second > third && first < third)
	{
		sa(stack_a, 0);
		rotate(stack_a, 0);
		sa(stack_a, 0);
	}
	else if (first < second && second > third && first > third)
	{
		rotate(stack_a, 0);
		sa(stack_a, 0);
	}
}

void	check_sorted_range(t_node **stack_a, t_node **stack_b)
{
	if (check_sorted(*stack_a))
		return ;
	if (ft_list_size(*stack_a) <= 3)
		sort_three(stack_a);
	else if (ft_list_size(*stack_a) <= 100)
		intel_sort(stack_a, stack_b, 11);
	else
		intel_sort(stack_a, stack_b, 30);
}
