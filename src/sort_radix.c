/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_radix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 20:33:27 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/10/16 21:05:03 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_index(t_node *head)
{
	t_node	*current;
	t_node	*temp;
	int		i;

	current = head;
	while (1)
	{
		i = 0;
		temp = head;
		while (1)
		{
			if (current->data > temp->data)
				i++;
			temp = temp->next;
			if (temp == head)
				break ;
		}
		current->index = i;
		current = current->next;
		if (current == head)
			break ;
	}
}

int	find_max_bits(t_node *head)
{
	int	lsize;
	int	max_bits;

	max_bits = 1;
	lsize = ps_lstsize(head);
	while ((lsize - 1) >> max_bits != 0)
		max_bits++;
	return (max_bits);
}

void	sort_radix(t_stack *stack)
{
	int	i;
	int	j;
	int	max_bits;
	int	lsize;

	i = 0;
	lsize = ps_lstsize(stack->head_a);
	max_bits = find_max_bits(stack->head_a);
	sort_index(stack->head_a);
	while (i < max_bits)
	{
		j = 0;
		while (j < lsize)
		{
			if ((stack->head_a->index >> i) & 1)
				ra_rb(&stack->head_a, 'a');
			else
				pb(stack);
			j++;
		}
		while (stack->head_b)
			pa(stack);
		i++;
	}
}
