/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:58:51 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/09/15 01:26:13 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(char *str, t_stack *stack)
{
	long int	sign;
	long int	nbr;

	sign = 1;
	while (*str)
	{
		nbr = 0;
		if ((*str >= 9 && *str <= 13) || *str == 32 || *str == '+')
			str++;
		else if (*str == '-')
		{
			sign *= -1;
			str++;
		}
		else if (*str >= '0' && *str <= '9')
		{
			while (*str >= '0' && *str <= '9')
				nbr = (nbr * 10) + (*str++ - '0');
			if (check_error(stack, (nbr * sign)))
				error_exit(stack);
			create_stack_a(stack, (nbr * sign));
		}
		else
			error_exit(stack);
	}
}

int	check_error(t_stack *stack, long int nbr)
{
	t_node	*current;

	if (!stack->head_a)
		return (0);
	if (nbr > INT_MAX || nbr < INT_MIN)
		return (1);
	current = stack->head_a;
	while (current != NULL)
	{
		if (current->data == nbr)
			return (1);
		current = current->next;
	}
	return (0);
}
