/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enregistrement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:55:28 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/08 17:21:36 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_nettoyage(char *piece)
{
	int		i;

	while (piece[0] == '.' && piece[4] == '.' && piece[8] == '.' && piece[12] == '.')
	{
		ft_memmove(piece, piece + 1, 3);
		piece[3] = '.';
		ft_memmove(piece + 4, piece + 5, 3);
		piece[7] = '.';
		ft_memmove(piece + 8, piece + 9, 3);
		piece[11] = '.';
		ft_memmove(piece + 12, piece + 13, 3);
		piece[15] = '.';
	}
	piece[16] = '\0';
	i = 12;
	while (piece[0] == '.' && piece[1] == '.' && piece[2] == '.' && piece[3] == '.')
	{
		ft_memmove(piece, piece + 4, 12);
		while (i <= 15)
			piece[i++] = '.';
	}
		ft_putchar('\n');
		ft_putstr(piece);
		ft_putchar('\n');
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
