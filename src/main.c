/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:10:29 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/09/21 00:32:12 by jnuncio-         ###   ########.fr       */
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
	pb(&stack);
	pb(&stack);
	pb(&stack);
	print_lst(stack.head_a, "Stack A");
	print_lst(stack.head_b, "Stack B");
	printf("\nPREV = %p | TAIL = %p\n\n", stack.head_a->prev, stack.tail_a);
	// sa_sb(stack.head_a, 'a');
	// print_lst(stack.head_a, "Stack A");
	// print_lst(stack.head_b, "Stack B");
	// sa_sb(stack.head_b, 'b');
	// print_lst(stack.head_a, "Stack A");
	// print_lst(stack.head_b, "Stack B");
	// ss(&stack);
	// print_stack(&stack);
	rr(&stack);
	print_lst(stack.head_a, "Stack A");
	print_lst(stack.head_b, "Stack B");
	free_lst(stack.head_a);
	free_lst(stack.head_b);
	return (0);
}
