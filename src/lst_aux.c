/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_aux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 20:07:20 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/09/24 00:27:43 by jnuncio-         ###   ########.fr       */
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
		stack->head_a->prev = new;
		stack->head_a->next = new;
	}
	else
	{
		stack->head_a->prev->next = new;
		new->prev = stack->head_a->prev;
		stack->head_a->prev = new;
		stack->head_a->prev->next = stack->head_a;
	}
}

void	print_lst(t_node *head, char *lst_name)
{
	t_node	*current;

	ft_printf("    %s\n", lst_name);
	if (!head)
		return ;
	current = head;
	while (1)
	{
		ft_printf("\t%d\t| me = %p | prev = %p | next = %p\n",
			current->data, current, current->prev, current->next);
		current = current->next;
		if (current == head)
			break ;
	}
}

void	free_lst(t_node **head)
{
	t_node	*current;
	t_node	*temp;

	if (*head == NULL)
		return ;
	current = *head;
	while (1)
	{
		temp = current;
		current = current->next;
		free(temp);
		if (current == *head)
			break ;
	}
	*head = NULL;
}
