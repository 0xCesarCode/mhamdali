/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhamdali <mhamdali@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 17:43:51 by mhamdali          #+#    #+#             */
/*   Updated: 2025/02/09 14:39:20 by mhamdali         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct s_node
{
	int				data;
	long			index;
	struct s_node	*next;
}	t_node;

t_node	*create_node(int data);
void	push_front(t_node **head, int data);
void	push_back(t_node **head, int data);
int		pop(t_node **head);
void	sa(t_node **stack_a, int flag);
void	sb(t_node **stack_b, int flag);
void	ss(t_node **stack_a, t_node **stack_b, int flag);
void	pa(t_node **stack_a, t_node **stack_b, int flag);
void	pb(t_node **stack_a, t_node **stack_b, int flag);
void	ra(t_node **stack_a, int flag);
void	rb(t_node **stack_b, int flag);
void	rr(t_node **stack_a, t_node **stack_b, int flag);
void	rotate(t_node **stack, int n);
void	rrr(t_node **stack_a, t_node **stack_b, int flag);
void	check_duplicate(t_node *head);
int		check_valid_number(char *str, t_node *stack, char **ptr);
void	check_number_overflow(long n, int sign, t_node *stack, char **ptr);
int		ft_list_size(t_node *begin_list);
void	intel_sort(t_node **stack_a, t_node **stack_b, int range);
int		find_max_index(t_node **stack_a, int *max);
int		is_sorted(t_node *stack);
void	exit_error(int flag, t_node *stack, char **ptr);
void	index_nodes(t_node **stack_a);
void	check_sorted_range(t_node **stack_a, t_node **stack_b);
void	free_stack(t_node *stack);
int		check_sorted(t_node *stack);
void	clean_pointer(char **ptr);
void	sort_three(t_node **stack_a);
void	sort_five(t_node **stack_a, t_node **stack_b);

#endif
