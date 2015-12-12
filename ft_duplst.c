/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_duplst.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/12 13:32:01 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/12 15:35:59 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_dbllist	*ft_duplst(t_dbllist *list)
{
	t_dbllist	*listdup;
	t_elem		*tmp;

	listdup = ft_lstdblnew();
	tmp = list->head;
	while (tmp != NULL)
	{
		ft_lstdbladd(&listdup, tmp->content, ft_strlen(tmp->content) + 1);
		tmp = tmp->next;
	}
	return (listdup);
}
