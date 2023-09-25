/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 23:18:50 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/09/25 21:04:04 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *stack)
{
	ra_rb(&stack->head_a, 'r');
	ra_rb(&stack->head_b, 'r');
	ft_putstr_fd("rr\n", 1);
}

void	rra_rrb(t_node **head, char flag)
{
	if (*head)
	{
		*head = (*head)->prev;
		if (flag == 'a' || flag == 'b')
			ft_printf("rr%c\n", flag);
	}
}

void	rrr(t_stack *stack)
{
	rra_rrb(&stack->head_a, 'r');
	rra_rrb(&stack->head_b, 'r');
	ft_putstr_fd("rrr\n", 1);
}
