/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_erros.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/07 16:02:45 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/09 14:04:58 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include "../includes/push_swap.h"
#include <stdio.h>

void	clean_pointer(char **ptr)
{
	int	i;

	if (!ptr || !*ptr)
		return ;
	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

void	exit_error(int flag, t_node *stack, char **ptr)
{
	if (ptr)
		clean_pointer(ptr);
	if (stack)
		free_stack(stack);
	if (flag == 0)
		write(2, "Error\n", 6);
	if (flag == 1)
		write(1, "KO\n", 3);
	exit(1);
}

void	check_duplicate(t_node *head)
{
	t_node	*first;
	t_node	*temp;

	first = head;
	while (first)
	{
		temp = first->next;
		while (temp)
		{
			if (first->data == temp->data)
			{
				free_stack(head);
				write(1, "Error\n", 6);
				exit(1);
			}
			temp = temp->next;
		}
		first = first->next;
	}
}

int	check_valid_number(char *str, t_node *stack, char **ptr)
{
	while (*str == ' ')
		str++;
	if (*str == '\0')
		exit_error(0, stack, ptr);
	if (*str == '+' || *str == '-')
		str++;
	if (*str == '\0')
		exit_error(0, stack, ptr);
	while (*str)
	{
		if (!ft_isdigit(*str))
			exit_error(0, stack, ptr);
		str++;
	}
	return (1);
}

void	check_number_overflow(long n, int sign, t_node *stack, char **ptr)
{
	if (sign == -1)
		n = n * -1;
	if (n > INT_MAX || n < INT_MIN)
		exit_error(0, stack, ptr);
}
