/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdoubleaddend.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:33:06 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/08 13:53:34 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lstdoubleaddend(t_doublelist **alst, t_doublelist *new)
{
	new->prev = *alst;
	new->next = NULL;
	*alst = new;
}
