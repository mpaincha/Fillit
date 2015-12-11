/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:37:37 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/11 11:53:40 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <math.h>

int		ft_tailledbt(int nb_pieces)
{
	float	c;
	int		cote;

	c = sqrt(4 * nb_pieces);
	cote = 0;
	if (c % (int)c != 0)
		cote = (int)c + 1;
	else
		cote = (int)c;
	return (cote);
}


