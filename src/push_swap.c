/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:10:29 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/06/25 18:11:28 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	char	**stack_a;
	int		i;

	i = 1;		
	if (ac < 2)
		return (0);
	stack_a = malloc(sizeof(char *) * ac);
	while (i < ac - 1)
	{
		stack_a[i] = ft_strdup(av[i]);
		ft_printf("%s | %s\n", stack_a[i], av[i]);
		i++;
	}
	stack_a[i] = NULL;
	ft_printf("-- | --\nsA | av\n");
	return (0);
}
