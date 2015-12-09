/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbladd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 09:43:37 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/09 11:38:16 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lstdbladd(t_dbllist **alst, t_dbllist *new)
{
	if (*alst)
	{
		(*alst)->prev = new;
		new->prev = NULL;
		new->next = *alst;
		*alst = new;
	}
	else
		*alst = new;
}
