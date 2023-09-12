/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:58:51 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/09/12 21:54:33 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(char *str, t_stack *stack)
{
	long int	sign;
	long int	nbr;

	sign = 1;
	(void)stack;
	while (*str)
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
		ps_create_stack(stack, (nbr * sign));
	}
}
