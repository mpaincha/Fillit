/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enregistrement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:55:28 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/08 15:33:26 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_nettoyage(char *piece)
{
	int		i;

	i = 0;
	if (piece[0] == '.' && piece[4] == '.' && piece[8] == '.' && piece[12] == '.')
	{
		while (piece[i])
		{
			if (1 <= i && i <= 3)
				piece[i - 1] = piece[i];
			if (5 <= i && i <= 8)
				piece[i - 1] = piece[i];
			if (1 <= i && i <= 3)
				piece[i - 1] = piece[i];

		}
	}

}

void	ft_enregistrement(char	*buf)
{
	char	*piece;
	int		nbpoint;
	int		i;
	int		j;

	i = 0;
	j = 0;
	nbpoint = 0;
	//ft_memcpy(piece, buf, 20);
	// reconnaissance de la piecei
	while (buf[i])
	{
		if (buf[i] != '\n')
		{
			piece[j] = buf[i];
			j++;
		}
		i++;
	}
	piece[j] = '\0';
	ft_putstr(piece);
	ft_putchar('\n');
	ft_nettoyage(piece);
	// if (la piece a deja ete enregistre, il faut simplement incrementer nb elem par 1)
	// else on cree le nouveau maillon (nouveau type de piece)
	//ft_lstdoublenew(piece, ft_strlen(piece), 1);
}
