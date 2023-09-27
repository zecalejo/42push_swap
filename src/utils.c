/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/12 23:02:05 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/09/27 23:48:37 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	only_spaces(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (!ft_isspace(*str))
			return (0);
		str++;
	}
	return (1);
}

char	*conv_int(t_stack *stack, char *s)
{
	stack->nbr = (stack->nbr * 10) + (*s++ - '0');
	stack->cnt++;
	return (s);
}

void	error_exit(t_stack *stack)
{
	ft_putstr_fd("Error\n", 2);
	if (stack->head_a)
		free_lst(&stack->head_a);
	if (stack->head_b)
		free_lst(&stack->head_b);
	exit(1);
}
