/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 21:24:45 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/06/14 19:07:51 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	pf_putchar(char c)
{
	return (write(1, &c, 1));
}

int	pf_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (write(1, "(null)", 6));
	while (s[i])
	{
		write(1, &s[i], 1);
		i++;
	}
	return (i);
}

int	pf_putptr_base(size_t n, char *base)
{
	char	c;
	int		cnt;
	size_t	blen;

	cnt = 0;
	blen = ft_strlen(base);
	if (n < blen)
	{
		c = base[n];
		write(1, &c, 1);
		cnt++;
	}
	else if (n >= blen)
	{
		cnt += pf_putptr_base(n / blen, base);
		cnt += pf_putptr_base(n % blen, base);
	}
	return (cnt);
}
