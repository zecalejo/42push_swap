/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:05:11 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/10/11 22:41:29 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_node *head, char flag)
{
	int	temp;

	if (head && head->next)
	{
		temp = head->data;
		head->data = head->next->data;
		head->next->data = temp;
		if (flag == 'a' || flag == 'b')
			ft_printf("s%c\n", flag);
	}
}

void	ss(t_stack *stack)
{
	sa_sb(stack->head_a, 's');
	sa_sb(stack->head_b, 's');
	ft_putstr_fd("ss\n", 1);
}

void	pa(t_stack *stack)
{
	t_node	*temp;

	if (stack->head_b)
	{
		temp = stack->head_b;
		if (stack->head_b->next == stack->head_b)
			stack->head_b = NULL;
		else
		{
			stack->head_b->next->prev = stack->head_b->prev;
			stack->head_b = stack->head_b->next;
			stack->head_b->prev->next = stack->head_b;
		}
		if (!stack->head_a)
		{
			stack->head_a = temp;
			stack->head_a->prev = temp;
		}
		temp->next = stack->head_a;
		stack->head_a->prev->next = temp;
		temp->prev = stack->head_a->prev;
		temp->next->prev = temp;
		stack->head_a = temp;
		ft_putstr_fd("pa\n", 1);
	}
}

void	pb(t_stack *stack)
{
	t_node	*temp;

	if (stack->head_a)
	{
		temp = stack->head_a;
		if (stack->head_a->next == stack->head_a)
			stack->head_a = NULL;
		else
		{
			stack->head_a->next->prev = stack->head_a->prev;
			stack->head_a = stack->head_a->next;
			stack->head_a->prev->next = stack->head_a;
		}
		if (!stack->head_b)
		{
			stack->head_b = temp;
			stack->head_b->prev = temp;
		}
		temp->next = stack->head_b;
		stack->head_b->prev->next = temp;
		temp->prev = stack->head_b->prev;
		temp->next->prev = temp;
		stack->head_b = temp;
		ft_putstr_fd("pb\n", 1);
	}
}

void	ra_rb(t_node **head, char flag)
{
	if (*head)
	{
		*head = (*head)->next;
		if (flag == 'a' || flag == 'b')
			ft_printf("r%c\n", flag);
	}
}
