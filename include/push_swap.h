/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/25 17:24:23 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/09/10 22:30:00 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_list {
	int				value;
	int				flag;
	struct s_list	*prev;
	struct s_list	*next;
}	t_list;

typedef struct s_stack {
	t_list	*head_a;
	t_list	*tail_a;
	t_list	*head_b;
	t_list	*tail_b;
}	t_stack;

void	ps_lstadd_back(t_stack *stack, int new_val);
void	ps_printlst(t_list *head);

#endif