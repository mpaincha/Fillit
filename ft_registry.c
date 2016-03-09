/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_registry.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:35:52 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/04 13:35:58 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static void	ft_cleaning(char *piece)
{
	int		i;

	while (piece[0] == '.' && piece[4] == '.' && piece[8] == '.' &&
			piece[12] == '.')
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
	while (piece[0] == '.' && piece[1] == '.' && piece[2] == '.' &&
			piece[3] == '.')
	{
		ft_memmove(piece, piece + 4, 12);
		while (i <= 15)
			piece[i++] = '.';
	}
}

void		ft_registry(char *buf, t_dbllist **list_piece, char lettre)
{
	char		piece[16];
	int			i;
	int			j;

	i = 0;
	j = 0;
	ft_strclr(piece);
	while (buf[i])
	{
		if (buf[i] != '\n')
			piece[j++] = buf[i];
		i++;
	}
	piece[j] = '\0';
	ft_cleaning(piece);
	ft_lstdbladd(list_piece, piece, ft_strlen(piece) + 1, lettre);
}
