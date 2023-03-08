/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/06 09:40:26 by ddyankov          #+#    #+#             */
/*   Updated: 2022/10/06 12:36:23 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*a;
	char	*b;
	size_t	counter;

	a = (char *) src;
	b = (char *) dest;
	counter = 0;
	if (!src && !dest)
		return (NULL);
	while (counter < n)
	{
		b[counter] = a[counter];
		counter++;
	}
	return (dest);
}
