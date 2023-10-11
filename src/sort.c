/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/28 19:34:16 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/10/11 22:50:25 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_node *head)
{
	t_node	*current;

	if (!head)
		return (1);
	current = head;
	while (1)
	{
		if (current->next == head)
			break ;
		if (current->data > current->next->data)
			return (0);
		current = current->next;
	}
	return (1);
}

void	small_sort(t_node **head, char flag)
{
	if ((*head)->data > (*head)->next->data
		&& (*head)->next->data > (*head)->prev->data)
		ra_rb(head, flag);
	if ((*head)->next->data > (*head)->data
		&& (*head)->next->data > (*head)->prev->data)
		rra_rrb(head, flag);
	if ((*head)->data > (*head)->next->data)
		sa_sb((*head), flag);
}

void	sort(t_stack *stack)
{
	int	lstsize;

	if (!stack)
		return ;
	lstsize = ps_lstsize(stack->head_a);
	if (lstsize <= 3 && !is_sorted(stack->head_a))
		small_sort(&stack->head_a, 'a');
	if (lstsize <= 5 && !is_sorted(stack->head_a))
		sort_five(stack);
}
