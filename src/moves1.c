/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/18 23:05:11 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/09/20 02:44:41 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa_sb(t_node *lst, char flag)
{
	int	temp;
	
	if (lst && lst->next)
	{
		temp = lst->data;
		lst->data = lst->next->data;
		lst->next->data = temp;
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

// void	ra(t_stack *stack)
// {
	
// }
