/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:12:51 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/09/15 01:46:06 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_conv(char c, va_list ap)
{
	size_t	ptr;

	if (c == 'c')
		return (pf_putchar(va_arg(ap, int)));
	else if (c == 's')
		return (pf_putstr(va_arg(ap, char *)));
	else if (c == 'p')
	{
		ptr = va_arg(ap, size_t);
		if (ptr == 0)
			return (write(1, "(nil)", 5));
		return (pf_putstr("0x") + pf_putptr_base(ptr, "0123456789abcdef"));
	}
	else if (c == 'd' || c == 'i')
		return (ft_putnbr_base(va_arg(ap, int), "0123456789"));
	else if (c == 'u')
		return (ft_putnbr_base(va_arg(ap, unsigned int), "0123456789"));
	else if (c == 'x')
		return (ft_putnbr_base(va_arg(ap, unsigned int), "0123456789abcdef"));
	else if (c == 'X')
		return (ft_putnbr_base(va_arg(ap, unsigned int), "0123456789ABCDEF"));
	else if (c == '%')
		return (pf_putchar('%'));
	return (0);
}

int	ft_printf(const char *s, ...)
{
	va_list	ap;
	int		i;
	int		cnt;

	va_start(ap, s);
	i = -1;
	cnt = 0;
	while (s[++i])
	{
		if (s[i] == '%')
		{
			i++;
			cnt += ft_conv(s[i], ap);
		}
		else
			cnt += pf_putchar(s[i]);
	}
	va_end(ap);
	return (cnt);
}
