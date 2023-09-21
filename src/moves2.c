/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/19 23:18:50 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/09/21 01:31:06 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_stack *stack)
{
	ra_rb(stack->head_a, 's');
	ra_rb(stack->head_b, 's');
	ft_putstr_fd("rr\n", 1);
}

// void	rra_rrb(t_node *head, char flag)
// {
// 	t_node	*temp;

// 	if (head && head->prev)
// 	{
// 		temp = head->prev;
// 		head->prev->next = head;
// 		head = head->next;
// 		head->prev = temp;
// 		if (flag == 'a' || flag == 'b')
// 			ft_printf("r%c\n", flag);
// 	}
// }

// void	rrr(t_stack *stack)
// {
	
// }
