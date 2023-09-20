/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:24:23 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/09/20 02:31:52 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_node {
	int				data;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	t_node		*head_a;
	t_node		*tail_a;
	t_node		*head_b;
	t_node		*tail_b;
	long int	nbr;
	long int	sign;
	int			cnt;
}	t_stack;

void	create_stack(t_stack *stack, int new_val);
void	print_lst(t_node *head, char *lst_name);
void	free_lst(t_node *head);
void	check_input(char *str, t_stack *stack);
void	check_sign(t_stack *stack, char *str);
void	error_exit(t_stack *stack);
void	sa_sb(t_node *lst, char flag);
void	ss(t_stack *stack);
void	pb(t_stack *stack);
void	pa(t_stack *stack);
void	ra(t_stack *stack);
void	rb(t_stack *stack);
void	sa(t_stack *stack);

int		check_error(t_stack *stack);

#endif