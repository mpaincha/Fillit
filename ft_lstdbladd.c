/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbladd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 09:43:37 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/18 13:55:01 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_sizecontent(char *content, t_elem *new_elem)
{
	size_t		i;
	size_t		lg;
	int			ok;

	i = 0;
	lg = 0;
	ok = 1;
	new_elem->width = 0;
	new_elem->height = 0;
	while (i < 16)
	{
		if (i % 4 == 0 && i > 0)
		{
			if (lg > new_elem->width)
				new_elem->width = lg;
			lg = 0;
			ok = 1;
		}
		if (content[i] != '.')
		{
			if (i >= 12)
				lg = i - 12;
			else if (i >= 8)
				lg = i - 8;
			else if (i >= 4)
				lg = i - 4;
			else
				lg = i;
			lg++;
		}
		if (content[i] != '.' && ok)
		{
			new_elem->height++;
			ok = 0;
		}
		i++;
	}
}

void		ft_lstdbladd(t_dbllist **list, void *content, size_t cont_size, char lettre)
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
	ft_sizecontent((char *)content, new_elem);
	new_elem->lettre = '\0';
	new_elem->next = NULL;
	new_elem->prev = NULL;
	new_elem->lettre = lettre;
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
