/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:07:20 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/09/10 22:29:48 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ps_lstadd_back(t_stack *stack, int new_val)
{
	t_list	*new;

	new = ft_calloc(1, sizeof(t_list));
	new->value = new_val;
	if (!stack->head_a)
	{
		stack->head_a = new;
		stack->tail_a = new;
		return ;
	}
	else
	{
		stack->tail_a->next = new;
		new->prev = stack->tail_a;
		stack->tail_a = new;
	}
}

void	ps_printlst(t_list *head)
{
	t_list	*current;

	current = head;
	ft_printf("Stack A\n");
	while (current)
	{
		ft_printf("   %d\n", current->value);
		current = current->next;
	}
	ft_printf("\n");
}
