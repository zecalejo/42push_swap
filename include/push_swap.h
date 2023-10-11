/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:24:23 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/10/11 22:59:20 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>

typedef struct s_node {
	int				data;
	int				index;
	int				digits;
	struct s_node	*prev;
	struct s_node	*next;
}	t_node;

typedef struct s_stack {
	t_node		*head_a;
	t_node		*head_b;
	long int	nbr;
	long int	sign;
	int			cnt;
}	t_stack;

void	create_stack(t_stack *stack, int new_val);
void	get_index(t_node **head, int i);
void	print_lst(t_node *head, char *lst_name);
void	free_lst(t_node **head);
void	check_input(char *str, t_stack *stack);
void	check_sign(t_stack *stack, char *str);
void	error_exit(t_stack *stack);

void	sa_sb(t_node *head, char flag);
void	ss(t_stack *stack);
void	pb(t_stack *stack);
void	pa(t_stack *stack);
void	ra_rb(t_node **head, char flag);
void	rr(t_stack *stack);
void	rra_rrb(t_node **head, char flag);
void	rrr(t_stack *stack);

int		smallest_value(t_node *head);
int		smallest_index(t_node *head);
int		is_sorted(t_node *head);
void	small_sort(t_node **head, char flag);
void	sort_five(t_stack *stack);
void	sort(t_stack *stack);

int		check_error(t_stack *stack);
int		ps_lstsize(t_node *head);
int		only_spaces(char *str);

char	*conv_int(t_stack *stack, char *s);

#endif