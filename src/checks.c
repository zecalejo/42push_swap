/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:58:51 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/09/12 01:05:25 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(char *str, t_stack *stack)
{
	long int	sign;
	long int	nbr;

	sign = 1;
	while (str)
	{
		nbr = 0;
		if ((*str >= 9 && *str <= 13) || *str == 32 || *str == '+')
			str++;
		if (*str == '-')
			sign *= -1;
		while (*str >= '0' && *str <= '9')
			nbr = (nbr * 10) + (*str++ - '0');
		if (nbr > INT_MAX || nbr < INT_MIN)
			return ;
		ps_lstadd_back(stack, (nbr * sign));
	}
}

void	init_stack(t_stack *stack, int count_a)
{
	stack->head_a = NULL;
	stack->head_b = NULL;
	stack->tail_a = NULL;
	stack->tail_b = NULL;
	stack->count_a = count_a;
	stack->count_b = 0;
}
