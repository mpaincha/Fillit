/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbladd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 09:43:37 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/12 14:11:11 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lstdbladd(t_dbllist **list, void *content, size_t cont_size)
{
	t_elem		*new_elem;

	new_elem = (t_elem *)malloc(sizeof(t_elem));
	if (new_elem == NULL)
		return ;
	new_elem->content = (void *)malloc(cont_size);
	if (new_elem->content == NULL)
	{
		free(new_elem);
		return ;
	}
	ft_memcpy(new_elem->content, content, cont_size);
	new_elem->next = NULL;
	new_elem->prev = NULL;
	if ((*list)->head == NULL)
		(*list)->head = new_elem;
	else
	{
		(*list)->tail->next = new_elem;
		new_elem->prev = (*list)->tail;
	}
	(*list)->tail = new_elem;
	(*list)->length++;
}
