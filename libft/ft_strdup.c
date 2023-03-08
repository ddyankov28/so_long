/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 12:10:21 by ddyankov          #+#    #+#             */
/*   Updated: 2022/10/19 11:19:56 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*news;
	int		a;

	a = 0;
	news = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!news)
		return (NULL);
	while (s[a])
	{
		news[a] = s[a];
		a++;
	}
	news[a] = '\0';
	return (news);
}
