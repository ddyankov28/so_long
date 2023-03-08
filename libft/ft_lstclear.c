/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddyankov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 11:48:45 by ddyankov          #+#    #+#             */
/*   Updated: 2022/10/30 13:16:44 by ddyankov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*newhead;

	if (lst && del)
	{
		while (*lst)
		{
			newhead = (*lst)->next;
			ft_lstdelone((*lst), del);
			*lst = newhead;
		}
		*lst = NULL;
	}
}
