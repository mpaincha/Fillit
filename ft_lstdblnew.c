/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdblnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 09:45:18 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/09 16:11:42 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_dbllist	*ft_lstdblnew(void const *content, size_t content_size)
{
	t_dbllist	*new_list;

	new_list = (t_dbllist *)malloc(sizeof(t_dbllist));
	if (new_list == NULL)
		return (NULL);
	if (content == NULL)
	{
		new_list->content = NULL;
		new_list->content_size = 0;
	}
	else
	{
		new_list->content = (void *)malloc(content_size + 1);
		ft_strclr(new_list->content);
		if (new_list->content == NULL)
			return (NULL);
		ft_strncpy(new_list->content, content, content_size);
		new_list->content_size = content_size;
		new_list->nb_elem = 1;
	}
	new_list->next = NULL;
	new_list->prev = NULL;
	return (new_list);
}
