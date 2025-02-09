/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:56:02 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/07 16:08:40 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	ra(t_node **stack_a, int flag)
{
	t_node	*first;
	t_node	*last;

	if (*stack_a && (*stack_a)->next)
	{
		first = *stack_a;
		last = *stack_a;
		while (last->next)
			last = last->next;
		*stack_a = first->next;
		first->next = NULL;
		last->next = first;
	}
	if (flag == 0)
		write(1, "ra\n", 3);
}

void	rb(t_node **stack_b, int flag)
{
	t_node	*first;
	t_node	*last;

	if (*stack_b && (*stack_b)->next)
	{
		first = *stack_b;
		last = *stack_b;
		while (last->next)
			last = last->next;
		*stack_b = (*stack_b)->next;
		first->next = NULL;
		last->next = first;
	}
	if (flag == 0)
		write(1, "rb\n", 3);
}

void	rr(t_node **stack_a, t_node **stack_b, int flag)
{
	ra(stack_a, 1);
	rb(stack_b, 1);
	if (flag == 0)
		write(1, "rr\n", 3);
}
