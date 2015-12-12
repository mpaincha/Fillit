/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:37:37 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/12 17:51:12 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putpiece(char *carre, char *piece, int cote, int pos)
{
	int		i;
	int		pose;

	i = 0;
	pose = 0;
	while (piece[i] && carre[pos])
	{
		if (piece[i] != '.')
		{
			if (carre[pos] == '.')
			{
				carre[pos] = piece[i];
				if ((pos + 1 == 4) || (pos + 1 == 9) || (pos + 1 == 14))
					pos = pos + (cote - 3);	
				else
					pos++;
				pose++;
			}
			else
				return ;
		
		}
		else if (pose != 0)
		{
			if ((pos + 1 == 4) || (pos + 1 == 9) || (pos + 1 == 14))
				pos = pos + (cote - 3);
			else
			pos++;
		}
		else
			pos = pos;
		i++;	
	}
}
//verif si carre parfait strictement plus grand que 4 de cote :i
//WARNING FAIRE LE CAS OU LE CARRE PARFAIT EST PLUS PETIT AUE $ DE COTES 

//verif si carre parfait strictement plus grand que 4 de cote :
int		ft_verifdispo(char *carre, char	*piece, int cote, int pos)
{
	int		i;
	int		hashtag;

	i = 0;
	hashtag = 0;
	while (i < 16 && carre[pos])
	{
		ft_putstr("\npos :"); //debug
		ft_putnbr(pos); //debug
		ft_putstr("\ni :"); //debug
		ft_putnbr(i); //debug
		if (piece[i] != '.')
		{
			ft_putchar(carre[pos]);
			if (carre[pos] == '.')
			{
				ft_putstr("rentree");
				if ((pos + 1 == 4) || (pos + 1 == 9) || (pos + 1 == 14))
					pos = pos + (cote - 3);	
				else
					pos++;
				hashtag++;
				ft_putnbr(hashtag);
			}
			else
				return (0);
		}
		else if (hashtag != 0)
		{
			if (pos + 1 == 4 || pos + 1 == 9 || pos + 1 == 14)
				pos = pos + (cote - 3);	
			else
				pos++;
		}
		else 
			pos = pos;
		i++;
	}
	return (hashtag == 4 ? 1 : 0);
}

int		ft_placement(t_dbllist *list_piece, char *carre, int cote, int nb_pieces, int *cpt_pieces)
{
	
	int			pos;
	t_dbllist	*ptr;

	pos = 0;
	while (carre[pos] != '\0' && list_piece->head->content)
	{
		ft_putstr("\n carre a remplir : \n"); //debug
		ft_affres(carre, cote); //debug
		if (carre[pos] != '.')
			pos++;
		else
		{
			ft_putstr("\n piece a placer :"); //debug
			ft_putstr(list_piece->head->content); //debug
			if (ft_verifdispo(carre, list_piece->head->content, cote, pos))
			{
				ft_putstr("dispo"); //debug
				ft_putpiece(carre, list_piece->head->content, cote, pos);
				ft_putstr("\nnew carre :\n"); //debug
				ft_putstr(carre); //debug
				ft_putstr("\ncpt piece :"); //debug
				ft_putnbr(*cpt_pieces); //debug
				ft_putstr("\n"); //debug
				list_piece->head = list_piece->head->next;
				*cpt_pieces = *cpt_pieces + 1;
				if (*cpt_pieces == nb_pieces)
				{
					ft_putstr("OUEP"); //debug
					return (1);
				}
				if (ft_placement(list_piece, carre, cote, nb_pieces, cpt_pieces))
				{
					ft_putstr("\nDONE\n"); //debug
					return (1);
				}
			}
			pos++;
		}
	}
	//carre[pos] = '.';
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

void	ft_affres(char *res, int cote)
{
	int		i;
	int		y;

	i = 0;
	y = 1;
	while (res[i])
	{
		if (y == cote)
		{
			ft_putchar(res[i++]);
			ft_putchar('\n');
			y = 1;
		}
		else
		{
			ft_putchar(res[i++]);
			y++;
		}
	}
}

char	*ft_resolution(char *res, t_dbllist	*list_piece, int nb_pieces)
{
	int			cote;
	t_dbllist	*listdup;
	int			cpt_pieces;

	cpt_pieces = 0;
	cote = ft_sqrtfillit(4 * nb_pieces);
	listdup = ft_duplst(list_piece);
	ft_putstr("cote : \n"); //debug
	ft_putnbr(cote); //debug
	ft_putstr(" \n"); //debug
	ft_putstr("list recue : \n"); //debug
	ft_putlsthead(list_piece); //debug
	ft_putstr("\nlist dup : \n"); //debug
	ft_putlsthead(listdup); //debug
	ft_putstr("\n"); //debug
	res = ft_carrevide(cote);
	if (ft_placement(list_piece, res, cote, nb_pieces, &cpt_pieces) == 0)
	{
		ft_putstr("impossible");
		ft_putstr("\nlist dup : \n"); //debug
		ft_putlsthead(listdup);
		cpt_pieces = 0;
		cote++;
		res = ft_carrevide(cote);
		ft_placement(listdup, res, cote + 1, nb_pieces, &cpt_pieces);
	}
	ft_putstr("\nres : \n"); //debug
	ft_putstr(res);
	ft_putstr("\nres : \n"); //debug
	ft_affres(res, cote);
	return (res);
	//	ft_placement(list_piece, car, cote);
}


