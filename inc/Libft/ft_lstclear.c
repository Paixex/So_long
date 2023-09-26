/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: digil-pa <digil-pa@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 19:03:25 by digil-pa          #+#    #+#             */
/*   Updated: 2022/11/18 14:48:10 by digil-pa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*link;

	if (!*lst || !lst)
		return ;
	while (*lst)
	{
		link = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = link;
	}
	lst = NULL;
}
