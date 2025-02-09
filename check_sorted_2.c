/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/09 14:04:58 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/09 14:04:58 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

int	find_min_index_push(t_node **stack, t_node **stack_b)
{
	t_node	*current;
	int		min;
	int		min_index;
	int		index;

	min = (*stack)->data;
	min_index = 0;
	index = 0;
	current = *stack;
	while (current != NULL)
	{
		if (current->data < min)
		{
			min = current->data;
			min_index = index;
		}
		index++;
		current = current->next;
	}
	while (min_index > 0)
	{
		ra(stack, 0);
		min_index--;
	}
	pb(stack, stack_b, 0);
	return (min_index);
}

/*
void	sort_five(t_node **stack_a, t_node **stack_b)
{
	find_min_index_push(stack_a, stack_b);
	find_min_index_push(stack_a, stack_b);
	sort_three(stack_a);
	while (*stack_b)
	{
		pa(stack_a, stack_b, 0);
		if ((*stack_a)->data > (*stack_a)->next->data)
			ra(stack_a, 0);
	}
}
*/
