/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/16 17:10:49 by ddyankov          #+#    #+#             */
/*   Updated: 2022/10/19 11:18:55 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	int	*p;

	if (nmemb >= 4294967295 || size >= 4294967295)
		return (NULL);
	p = malloc(nmemb * size);
	if ((size == 0 || p == NULL) && p == NULL)
		return (malloc(0));
	else
		ft_bzero(p, nmemb * size);
	return (p);
}
