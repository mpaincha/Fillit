/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:37:37 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/11 18:04:51 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//verif si carre parfait strictement plus grand que 4 de cote :
int		ft_verifdispo(char *carre, char	*piece, int cote, int pos)
{
	int		i;
	int		hashtag;

	i = 0;
	hashtag = 0;
	while (piece[i] && carre[pos])
	{
		ft_putstr("deplacement piece i et carre pos \n"); //debug
		ft_putstr("i : "); //debug
		ft_putnbr(i); //debug
		ft_putstr("\n pos : "); //debug
		ft_putnbr(pos); //debug
		ft_putstr(" \n"); //debug
		if (piece[i] != '.')
		{
			if (carre[pos] == '.')
			{
				if (i == 3 || i == 7 || i == 11 || i == 18)
					pos = pos + (cote - 4);				
				else
					pos++;
				i++;
				hashtag++;
			}
			else
				return (0);
		}
		i++;
	}
	return (hashtag == 4 ? 1 : 0);
}

int		ft_placement(t_dbllist *list_piece, char *carre, int cote)
{
	
	int		pos;

	pos = 0;
	while (carre[pos])
	{
		ft_putstr("deplacement carre pos \n"); //debug
		if (carre[pos] != '.')
		{
			ft_putstr("carre pos != ."); //debug
			pos++;
		}
		else
		{
			ft_putstr("carre pos == . \n"); //debug
			ft_putstr(list_piece->head->content);
			if (ft_verifdispo(carre, list_piece->head->content, cote, pos))
			{
				ft_putstr("ici \n");
				ft_putstr("dispo");
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

char	*ft_resolution(char *res, t_dbllist	*list_piece, int nb_pieces)
{
	int		cote;

	cote = ft_sqrtfillit(4 * nb_pieces);
	ft_putstr("carre vide : \n"); //debug
	ft_putstr(ft_carrevide(cote)); //debug
	ft_putstr(" \n"); //debug
	ft_putstr("list recue : \n"); //debug
	ft_putlsthead(list_piece); //debug
	ft_putstr("\n"); //debug
//	ft_placement(list_piece, ft_carrevide(cote), cote);
	ft_placement(list_piece, "................", cote);
	return (res);
}


