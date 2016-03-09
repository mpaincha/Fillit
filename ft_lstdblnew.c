/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdblnew.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 09:45:18 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/30 17:42:14 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_dbllist	*ft_lstdblnew(void)
{
	t_dbllist	*list;

	list = (t_dbllist *)malloc(sizeof(t_dbllist));
	if (list == NULL)
		return (NULL);
	else
	{
		list->tail = NULL;
		list->head = NULL;
	}
	return (list);
}
