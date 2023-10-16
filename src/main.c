/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:10:29 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/10/16 21:07:15 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	static t_stack	stack;
	int				i;

	i = 1;
	if (ac < 2)
		return (0);
	while (i < ac)
	{
		check_input(av[i], &stack);
		i++;
	}
	sort(&stack);
	if (stack.head_a)
		free_lst(&stack.head_a);
	if (stack.head_b)
		free_lst(&stack.head_b);
	return (0);
}
