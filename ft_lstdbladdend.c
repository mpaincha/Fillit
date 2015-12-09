/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdbladdend.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 09:44:35 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/09 09:44:46 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lstdbladdend(t_dbllist **alst, t_dbllist *new)
{
	new->prev = *alst;
	new->next = NULL;
	*alst = new;
}
