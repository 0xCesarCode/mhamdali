/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:43:38 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/07 16:10:49 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

void	sa(t_node **stack_a, int flag)
{
	int	temp;

	if (*stack_a && (*stack_a)->next)
	{
		temp = (*stack_a)->data;
		(*stack_a)->data = (*stack_a)->next->data;
		(*stack_a)->next->data = temp;
	}
	if (flag == 0)
		write(1, "sa\n", 3);
}

void	sb(t_node **stack_b, int flag)
{
	int	temp;

	if (*stack_b && (*stack_b)->next)
	{
		temp = (*stack_b)->data;
		(*stack_b)->data = (*stack_b)->next->data;
		(*stack_b)->next->data = temp;
	}
	if (flag == 0)
		write(1, "sb\n", 3);
}

void	ss(t_node **stack_a, t_node **stack_b, int flag)
{
	sa(stack_a, 1);
	sb(stack_b, 1);
	if (flag == 0)
		write(1, "ss\n", 3);
}
