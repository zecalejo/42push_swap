/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort5.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/11 20:39:31 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/10/11 22:59:32 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	smallest_value(t_node *head)
{
	int		smallest;
	t_node	*current;

	smallest = head->data;
	current = head;
	while (1)
	{
		if (current->data < smallest)
			smallest = current->data;
		current = current->next;
		if (current == head)
			break ;
	}
	return (smallest);
}

int	smallest_index(t_node *head)
{
	t_node	*smallest;
	t_node	*current;

	smallest = head;
	current = head;
	while (1)
	{
		if (current->data < smallest->data)
			smallest = current;
		current = current->next;
		if (current == head)
			break ;
	}
	return (smallest->index);
}

void	sort_five(t_stack *stack)
{
	int	smallest_i;
	int	smallest_val;
	int	i;

	i = 2;
	while (i)
	{
		get_index(&stack->head_a, 0);
		smallest_val = smallest_value(stack->head_a);
		smallest_i = smallest_index(stack->head_a);
		if (smallest_i <= i)
			while (stack->head_a->data != smallest_val)
				ra_rb(&stack->head_a, 'a');
		else
			while (stack->head_a->data != smallest_val)
				rra_rrb(&stack->head_a, 'a');
		pb(stack);
		i--;
	}
	if (!is_sorted(stack->head_a))
		small_sort(&stack->head_a, 'a');
	pa(stack);
	pa(stack);
}
