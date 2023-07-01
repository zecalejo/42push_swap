/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 18:42:12 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/06/14 18:42:36 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putnbr_base(long long n, char *base)
{
	long long	blen;
	int			cnt;
	char		c;

	cnt = 0;
	blen = (long long)ft_strlen(base);
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
		cnt++;
	}
	if (n >= 0 && n < blen)
	{
		c = base[n];
		write(1, &c, 1);
		cnt++;
	}
	else if (n >= blen)
	{
		cnt += ft_putnbr_base(n / blen, base);
		cnt += ft_putnbr_base(n % blen, base);
	}
	return (cnt);
}
