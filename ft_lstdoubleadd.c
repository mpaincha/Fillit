/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdoubleadd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 13:33:15 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/08 13:53:19 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lstdoubleadd(t_doublelist **alst, t_doublelist *new)
{
	new->prev = NULL;
	new->next = *alst;
	*alst = new;
}
