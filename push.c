/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:43:33 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/07 16:07:45 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	pa(t_node **stack_b, t_node **stack_a, int flag)
{
	t_node	*temp;

	if (*stack_b == NULL)
		return ;
	temp = *stack_b;
	*stack_b = (*stack_b)->next;
	temp->next = *stack_a;
	*stack_a = temp;
	if (flag == 0)
		write(1, "pa\n", 3);
}

void	pb(t_node **stack_a, t_node **stack_b, int flag)
{
	int	value;

	if (*stack_a)
	{
		value = pop(stack_a);
		push_front(stack_b, value);
	}
	if (flag == 0)
		write(1, "pb\n", 3);
}
