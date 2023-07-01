/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jnuncio- <jnuncio-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 22:39:01 by jnuncio-          #+#    #+#             */
/*   Updated: 2023/06/13 19:15:27 by jnuncio-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wrdcnt(char const *str, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	while (str[i])
	{
		if (str[i] != c && (str[i + 1] == c || str[i + 1] == '\0'))
			cnt++;
		i++;
	}
	return (cnt);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	ptr = (char **)malloc((ft_wrdcnt(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	j = 0;
	while (*s != '\0')
	{
		if (*s != c && *s != '\0')
		{
			i = 0;
			while (s[i] && s[i] != c)
				i++;
			ptr[j++] = ft_substr(s, 0, i);
			s += i;
		}
		else
			s++;
	}
	ptr[j] = NULL;
	return (ptr);
}
