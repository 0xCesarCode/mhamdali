/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intel_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:03:33 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/09 14:05:21 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"

int	ft_list_size(t_node *begin_list)
{
	int		i;
	t_node	*temp;

	i = 0;
	temp = begin_list;
	while (temp)
	{
		temp = temp->next;
		i++;
	}
	return (i);
}

int	find_max_index(t_node **stack_a, int *max)
{
	int		index;
	t_node	*temp;

	index = 0;
	temp = *stack_a;
	*max = temp->data;
	while (temp)
	{
		if (*max < temp->data)
			*max = temp->data;
		temp = temp->next;
	}
	temp = (*stack_a);
	while (temp)
	{
		if (temp->data == *max)
			return (index);
		index++;
		temp = temp->next;
	}
	return (index);
}

void	sort_array(int *array, int size, int k)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (k == 0 && array[j] > array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			if (k == 2 && array[j] < array[j + 1])
			{
				temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
			j++;
		}
		i++;
	}
}

void	index_nodes(t_node **stack_a)
{
	int		i;
	int		size;
	t_node	*temp;
	int		check;
	int		array[10000];

	temp = (*stack_a);
	i = 0;
	size = ft_list_size(*stack_a);
	while (i < size)
	{
		array[i] = temp->data;
		i++;
		temp = temp->next;
	}
	check = is_sorted(*stack_a);
	sort_array(array, ft_list_size(*stack_a), check);
	i = 0;
	while (i < size)
	{
		temp = (*stack_a);
		while (temp)
		{
			if (array[i] == temp->data)
				temp->index = i;
			temp = temp->next;
		}
		i++;
	}
}

void	intel_sort(t_node **stack_a, t_node **stack_b, int range)
{
	int	size;
	int	index_max;
	int	max;

	size = ft_list_size(*stack_a);
	index_nodes(stack_a);
	while (size != 0)
	{
		if ((*stack_a)->index <= ft_list_size(*stack_b))
			pb(stack_a, stack_b, 0);
		else if ((*stack_a)->index < ft_list_size(*stack_b) + range)
		{
			pb(stack_a, stack_b, 0);
			rb(stack_b, 0);
		}
		else
			ra(stack_a, 0);
		size = ft_list_size(*stack_a);
	}
	size = ft_list_size(*stack_b);
	while (size)
	{
		index_max = find_max_index(stack_b, &max);
		if (index_max < size / 2)
			while ((*stack_b)->data != max)
				rb(stack_b, 0);
		else
			while ((*stack_b)->data != max)
				rotate(stack_b, 1);
		pa(stack_b, stack_a, 0);
		size = ft_list_size(*stack_b);
	}
}
