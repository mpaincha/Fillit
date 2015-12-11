/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:37:37 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/11 16:44:37 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_verifdispo(char *carre, char	*piece, int cote, int pos)
{
	int		i;

	i = 0;
	while (piece[i])
	{
		if (piece[i] != '.' && carre[pos] == '.')
			i++;
		i++;
	}
	return (1);
}

int		ft_placement(t_dbllist *list_piece, char *carre, int cote)
{
	
	int		pos;

	pos = 0;
	while (carre[pos])
	{
		if (carre[pos] != '.')
			pos++;
		else
		{
			if (ft_verifdispo(carre, list_piece->head->content, cote, pos))
			{
			//	ft_putpiece(list_piece->head, cote);
			//	if (ft_placement(list_piece->head->next))
					return (1);
			}
			else
				pos++;
		}
	}
	carre[pos] = '.';
	return (0);
}

char	*ft_carrevide(int c)
{
	int		i;
	int		lg;
	char	*carre;

	i = 0;
	lg = c * c;
	carre = (char *)malloc(sizeof(char) * lg + 1);
	if (carre == NULL)
		return (NULL);
	while (i != lg)
		carre[i++] = '.';
	carre[i] = '\0';
	return (carre);
}

/*
int		ft_tailledbt(int nb_pieces)
{
	int		c;

	return (c);
}
*/
char	*ft_resolution(char *res, t_dbllist	*list_piece, int nb_pieces)
{
	int		cote;

	cote = ft_sqrtfillit(4 * nb_pieces);
	ft_putstr("carre vide : \n"); //debug
	ft_putstr(ft_carrevide(cote)); //debug
	ft_putstr(" \n"); //debug
	ft_putstr("list recue : \n"); //debug
	ft_putlsthead(list_piece); //debug
	ft_placement(list_piece, ft_carrevide(cote), cote);
	return (res);
}


