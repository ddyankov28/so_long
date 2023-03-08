/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/14 11:38:43 by ddyankov          #+#    #+#             */
/*   Updated: 2022/10/14 15:23:49 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			counter;
	unsigned char	*a;
	unsigned char	symbol;

	a = (unsigned char *)s;
	symbol = (unsigned char)c;
	counter = 0;
	while (counter < n)
	{
		if (*a == symbol)
		{
			return (a);
		}
		a++;
		counter++;
	}
	return (NULL);
}
