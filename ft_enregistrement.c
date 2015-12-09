/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enregistrement.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/08 10:55:28 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/09 14:57:40 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		ft_testexist(t_dbllist **list_piece, char *piece)
{
	t_dbllist	*new_piece;
	
	new_piece = ft_lstdblnew(piece, ft_strlen(piece));
	ft_lstdbladd(list_piece, new_piece);
}

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
}

void	ft_enregistrement(char	*buf, t_dbllist **list_piece)
{
	char		piece[16];
	int			nbpoint;
	int			i;
	int			j;

	i = 0;
	j = 0;
	nbpoint = 0;
	ft_strclr(piece);
	//ft_memcpy(piece, buf, 20);
	// reconnaissance de la piece
	while (buf[i])
	{
		if (buf[i] != '\n')
			piece[j++] = buf[i];
		i++;
	}
	piece[j] = '\0';
	ft_putstr(piece); //debug
	ft_putchar('\n'); //debug
	ft_nettoyage(piece);
	ft_putstr(piece); //debug
	ft_putchar('\n'); //debug
	ft_putchar('\n'); //debug
	ft_testexist(list_piece, piece);
	ft_putstr("affichage list : "); //debug
	if (list_piece)
		ft_putstr((char *)(*list_piece)->content); //debug
}
