/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 12:24:30 by ddyankov          #+#    #+#             */
/*   Updated: 2022/10/24 15:09:18 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str;
	unsigned int	a;

	if (!s)
		return (NULL);
	a = 0;
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	while (str[a])
	{
		str[a] = (f)(a, str[a]);
		a++;
	}
	return (str);
}
