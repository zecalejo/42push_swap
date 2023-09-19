/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:05:11 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/09/19 01:28:26 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pb(t_stack *stack)
{
	t_node	*temp;

	if (stack->head_a)
	{
		temp = stack->head_a;
		if (!stack->head_a->next)
		{
			stack->head_a = NULL;
			stack->tail_a = NULL;
		}
		else
		{
			stack->head_a = stack->head_a->next;
			stack->head_a->prev = NULL;
		}
		temp->next = stack->head_b;
		if (stack->head_b)
			stack->head_b->prev = temp;
		stack->head_b = temp;
		if (stack->head_b->next == NULL)
			stack->tail_b = temp;
		ft_putstr_fd("pb\n", 1);
	}
}

void	pa(t_stack *stack)
{
	t_node	*temp;

	if (stack->head_b)
	{
		temp = stack->head_b;
		if (!stack->head_b->next)
		{
			stack->head_b = NULL;
			stack->tail_b = NULL;
		}
		else
		{
			stack->head_b = stack->head_b->next;
			stack->head_b->prev = NULL;
		}
		temp->next = stack->head_a;
		if (stack->head_a)
			stack->head_a->prev = temp;
		stack->head_a = temp;
		if (stack->head_a->next == NULL)
			stack->tail_a = temp;
		ft_putstr_fd("pa\n", 1);
	}
}
