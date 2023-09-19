/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:07:20 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/09/19 01:48:17 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_stack(t_stack *stack, int new_val)
{
	t_node	*new;

	new = ft_calloc(1, sizeof(t_node));
	new->data = new_val;
	if (!stack->head_a)
	{
		stack->head_a = new;
		stack->tail_a = new;
	}
	else
	{
		stack->tail_a->next = new;
		new->prev = stack->tail_a;
		stack->tail_a = new;
	}
}

void	print_lst(t_node *head, char *lst_name)
{
	t_node	*current;

	current = head;
	ft_printf("%s\n", lst_name);
	while (current)
	{
		ft_printf("   %d\n", current->data);
		current = current->next;
	}
}

void	free_lst(t_node *head)
{
	t_node	*temp;

	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
