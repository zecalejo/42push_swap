/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/11 20:58:51 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/09/27 21:54:12 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_input(char *str, t_stack *stack)
{
	stack->sign = 1;
	if (!str || only_spaces(str))
		error_exit(stack);
	while (*str)
	{
		stack->nbr = 0;
		stack->cnt = 0;
		if (ft_isspace(*str) || *str == '-' || *str == '+')
			check_sign(stack, str);
		else if (*str >= '0' && *str <= '9')
		{
			while (*str >= '0' && *str <= '9')
			{
				stack->nbr = (stack->nbr * 10) + (*str++ - '0');
				stack->cnt++;
			}
			if (check_error(stack))
				error_exit(stack);
			create_stack(stack, (stack->nbr * stack->sign));
			str--;
		}
		else
			error_exit(stack);
		str++;
	}
}

void	check_sign(t_stack *stack, char *str)
{
	if (!str)
		return ;
	stack->sign = 1;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			stack->sign = -1;
		str++;
		if (!(*str >= '0' && *str <= '9'))
			error_exit(stack);
	}
}

int	check_error(t_stack *stack)
{
	t_node	*current;

	if (!stack->head_a)
		return (0);
	if (stack->nbr > INT_MAX || stack->nbr < INT_MIN || stack->cnt > 10) 
		return (1);
	if (stack->head_a->data == stack->nbr)
		return (1);
	current = stack->head_a->next;
	while (current != stack->head_a)
	{
		if (current->data == stack->nbr)
			return (1);
		current = current->next;
	}
	return (0);
}
