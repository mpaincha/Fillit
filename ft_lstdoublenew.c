/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdoublenew.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 11:09:18 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/08 14:14:05 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_doublelist	*ft_lstdoublenew(void const *content, size_t content_size, size_t nb_elem)
{
	t_doublelist	*new_list;

	new_list = (t_doublelist *)malloc(sizeof(t_doublelist));
	if (new_list == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
	}
	else
	{
		new_list->content = (void *)malloc(sizeof(content));
		if (new_list->content == NULL)
			return (NULL);
		ft_memcpy(new_list->content, content, content_size);
		new_list->content_size = content_size;
		new_list->nb_elem = nb_elem + 1;
	}
	new_list->next = NULL;
	new_list->prev = NULL;
	return (new_list);
}
