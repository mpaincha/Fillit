/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:37:37 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/14 11:30:31 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//REGARDER QUAND LA PIECE NES PAS TESTE A PARTIR DE LA POSITION POS 0)
void	ft_putpiece(char *carre, char *piece, int cote, t_pos pos)
{
	int		i;
	int		pose;
	int		j;

	i = 0;
	pose = 0;
	j = pos.ini;
	ft_putstr("\nPUT PIECE:");
	ft_putstr("\npos ini:");
	ft_putnbr(pos.ini);
	while (piece[i] && carre[j])
	{
		if (piece[i] != '.')
		{
			if (carre[j] == '.')
			{
				ft_putstr("\nPUT PIECE:");
				carre[j] = piece[i];
				ft_putstr("\nj avant:");
				ft_putnbr(j);
				j = ft_newpos(j, pos);
				ft_putstr("\nj apres");
				ft_putnbr(j);
				pose++;
			}
			else
				return ;
		
		}
		else if (pose != 0)
			j = ft_newpos(j, pos);
		else
			j = j;
		i++;	
	}
	ft_putstr("\nNEW CARRE:");
	ft_putstr(carre);
}
				
int		ft_newpos(int j, t_pos pos)
{
	ft_putstr("COUCOU J");
	ft_putnbr(j);
	if (j == pos.max1)
		j = pos.min1;
	else if (j == pos.max2)
		j = pos.min2;
	else if (j == pos.max3)
		j = pos.min3;
	else
		j++;
	ft_putstr("CIAO J");
	ft_putnbr(j);
	ft_putstr("\n");
	return (j);
}

void	ft_structpos(t_pos pos, int cote)
{
	pos.max1 = pos.ini + 3;
	pos.min1 = pos.ini + cote;
	pos.max2 = pos.min1 + 3;
	pos.min2 = pos.min1 + cote;
	pos.max3 = pos.min2 + 3;
	pos.min3 = pos.min2 + cote;
	pos.max4 = pos.min3 + 3;

	ft_putstr("\npos ini:");
	ft_putnbr(pos.ini);
	ft_putstr("\npos max1:");
	ft_putnbr(pos.max1);
	ft_putstr("\npos min1:");
	ft_putnbr(pos.min1);
	ft_putstr("\npos max2:");
	ft_putnbr(pos.max2);
	ft_putstr("\npos min2:");
	ft_putnbr(pos.min2);
	ft_putstr("\npos max3:");
	ft_putnbr(pos.max3);
	ft_putstr("\npos min3:");
	ft_putnbr(pos.min3);
	ft_putstr("\npos max4:");
	ft_putnbr(pos.max4);
}

//verif si carre parfait strictement plus grand que 4 de cote :i
//WARNING FAIRE LE CAS OU LE CARRE PARFAIT EST PLUS PETIT que 4 DE COTES 

//verif si carre parfait strictement plus grand que 4 de cote :
int		ft_verifdispo(char *carre, char	*piece, int cote, t_pos pos)
{
	int		i;
	int		hashtag;
	int		j;

	j = pos.ini;
	i = 0;
	hashtag = 0;
	while (i < 16 && carre[j])
	{
		ft_putstr("\npos :"); //debug
		ft_putnbr(j); //debug
		ft_putstr("\ni :"); //debug
		ft_putnbr(i); //debug
		if (piece[i] != '.')
		{
			ft_putchar(carre[j]); //debug
			if (carre[j] == '.')
			{
				ft_putstr("rentree");
				j = ft_newpos(j, pos);
				hashtag++;
				ft_putnbr(hashtag);
			}
			else
				return (0);
		}
		else if (hashtag != 0)
			j = ft_newpos(j, pos);
		else 
			j = j;
		i++;
	}
	return (hashtag == 4 ? 1 : 0);
}

int		ft_placement(t_dbllist *list_piece, char *carre, int cote, int nb_pieces, int *cpt_pieces)
{
	
	t_pos		pos;
	t_dbllist	*ptr;

	pos.ini = 0;
	ft_putnbr(pos.ini);	
	
	ft_structpos(pos, cote);
	while (carre[pos.ini] != '\0' && list_piece->head->content)
	{
		ft_putstr("\n carre a remplir : \n"); //debug
		ft_affres(carre, cote); //debug
		if (carre[pos.ini] != '.')
			pos.ini++;
		else
		{
			ft_putstr("\n piece a placer :"); //debug
			ft_putstr(list_piece->head->content); //debug
			ft_putstr("\n pos ini :"); //debug
			ft_putnbr(pos.ini);	
			ft_structpos(pos, cote); 
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
			pos.ini++;
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
