/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdblmap.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 09:56:02 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/09 09:58:21 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_dbllist	*ft_lstdblmap(t_dbllist *lst, t_dbllist *(*f)(t_dbllist *elem))
{
	t_dbllist	*new_list;

	new_list = (t_dbllist *)malloc(sizeof(t_dbllist));
	if (new_list == NULL || lst == NULL)
		return (NULL);
	new_list = (*f)(lst);
	new_list->next = ft_lstdblmap(lst->next, f);
	new_list->next->prev = new_list;
	return (new_list);
}
