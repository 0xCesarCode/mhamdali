/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intel_sort_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:19:40 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/08 10:23:50 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

int	is_sorted(t_node *stack)
{
	int		i;
	float	j;

	j = ft_list_size(stack);
	i = 0;
	while (stack && stack->next)
	{
		if (stack->data > stack->next->data)
			i++;
		stack = stack->next;
	}
	if (i == ft_list_size(stack))
		return (-1);
	if ((float)i > (float)(j / 1.5))
		return (2);
	if (i == 0)
		return (1);
	return (0);
}
