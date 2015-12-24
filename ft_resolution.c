/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:37:37 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/24 11:08:23 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//verif si carre parfait strictement plus grand que 4 de cote :i
//WARNING FAIRE LE CAS OU LE CARRE PARFAIT EST PLUS PETIT que 4 DE COTES 

//verif si carre parfait strictement plus grand que 4 de cote :

void	ft_move(int	*i, int *x, int *y, int cote)
{
	if (cote >= 4)
	{
		if (*i >= 11)
		{
			*y = *i - 11;
			*x = 3;
		}
		else if (*i >= 7)
		{
			*y = *i - 7;
			*x = 2;
		}
		else if (*i >= 3)
		{
			*y = *i - 3;
			*x = 1;
		}
		else
		{
			*y = *i + 1;
			*x = 0;
		}
		*i = *i + 1;
	}
	else
	{
		ft_putstr("a traiter");
	}
}

int		ft_verifdispo(char **carre, t_elem	*piece, t_pos *pos, int cote)
{
	int		i;
	int		hashtag;
	int		a;
	int		b;
	char	*piece1;
	int		y;
	int		x;
	int		debug1; //debug
	int		debug2; //debug

	piece1 = (char *)(piece->content);
	a = 0;
	b = 0;
	i = 0;
	y = 0;
	x = 0;
	hashtag = 0;
	debug1 = 0; //debug
	debug2 = 0; //debug
	while (carre[a] && carre[a][b] && hashtag != 4)
	{
		debug1 = a + x; //debug
		debug2 = b + y; //debug
		ft_putstr("\n--------\nGRANDE BOUCLE - VERIF DISPO : ");
		ft_putstr("\npos x : ");
		ft_putnbr(debug1);
		ft_putstr("\npos y : ");
		ft_putnbr(debug2);
		ft_putstr("\n>> Contenu du carre a remplir :  >> "); //debug
		ft_putchar(carre[a][b]);
		ft_putstr(" <<\n"); //debug
		if (carre[a + x][b + y] == '\0')
		{
			ft_putstr("\npos x : ");
			ft_putnbr(debug1);
			ft_putstr("\npos y : ");
			ft_putnbr(debug2);
			ft_putstr("\n>>>>>Search in a new line :"); //debug
			a++;
			b = 0;
			x = 0;
			y = 0;
		}
		else if (carre[a + x][b + y] == '.')
		{
			ft_putstr("\n"); //debug
			while (i < 16 && hashtag != 4) //&& carre[a + x] && carre[a + x][b + y])
			{
				if (piece1[i] != '.' && (carre[a + x] == '\0' || carre[a + x][b + y] == '\0'))
				{
					ft_putstr("/// BREAK - Le piece sort du grd carre \\\\");
					i = 0;
					if (carre[a][b + 1])
					{
						b++;
						x = 0;
						y = 0;
						hashtag = 0;
					}
					else
					{
						a++;
						b = 0;
						x = 0;
						y = 0;
						hashtag = 0;
					}
					break ;
				}
				if (carre[a + x] && carre[a + x][b + y] && carre[a + x][b + y] != '.' && piece1[i] == '.')
				{
					ft_putstr("\npiece . et carre pris\n");
					ft_move(&i, &x, &y, cote);
				}
				while (i < 16 && hashtag != 4 && carre[a + x] && carre[a + x][b + y] && carre[a + x][b + y] == '.')
				{
					ft_putstr("\nBOUCLE 1 - Emplacement Grd Carre vide : "); //debug
					if (hashtag == 0 && piece1[i] == '.')
						break ;
					else if (piece1[i] == '.')
					{
						debug1 = a + x; //debug
						debug2 = b + y; //debug
						ft_putstr("\npiece1[i] = . : "); //debug
						ft_putstr("\ni : "); //debug
						ft_putnbr(i); //debug
						ft_putstr("\npos x : "); //debug
						ft_putnbr(debug1); //debug
						ft_putstr("\npos y : "); //debug
						ft_putnbr(debug2); //debug
						ft_move(&i, &x, &y, cote);
						ft_putstr("\ni : "); //debug
						ft_putnbr(i); //debug
						debug1 = a + x; //debug
						debug2 = b + y; //debug
						ft_putstr("\na : "); //debug
						ft_putnbr(a); //debug
						ft_putstr("\nb : "); //debug
						ft_putnbr(b); //debug
						ft_putstr("\npos x : "); //debug
						ft_putnbr(debug1); //debug
						ft_putstr("\npos y : "); //debug
						ft_putnbr(debug2); //debug
					}
					else
					{
						hashtag++;
						debug1 = a + x; //debug
						debug2 = b + y; //debug
						ft_putstr("\nBOUCLE 3 : "); //debug
						ft_putstr("\nposition ok\n>>>>>>>>>>>>>>>>>>>>>> ! <<< NB HASHTAG : "); //debug
						ft_putnbr(hashtag); //debug
						ft_putstr("\ni : "); //debug
						ft_putnbr(i); //debug
						ft_putstr("\npos x : "); //debug
						ft_putnbr(debug1); //debug
						ft_putstr("\npos y : "); //debug
						ft_putnbr(debug2); //debug
						ft_move(&i, &x, &y, cote);
					}
				}
				if (i < 16 && piece1[i] == '.' && hashtag != 4 && carre[a + x] && carre[a + x][b + y] == '\0')
				{
					ft_putstr("\nBOUCLE 4 - emplcmt piece vide"); //debug
					ft_putstr("\ni : "); //debug
					ft_putnbr(i); //debug
					ft_move(&i, &x, &y, cote);
					ft_putstr("\n x : "); //debug
					ft_putnbr(x); //debug
					ft_putstr("\ny : "); //debug
					ft_putnbr(y); //debug
						debug1 = a + x; //debug
						debug2 = b + y; //debug
						ft_putstr("\na : "); //debug
						ft_putnbr(a); //debug
						ft_putstr("\nb : "); //debug
						ft_putnbr(b); //debug
						ft_putstr("\npos x : "); //debug
						ft_putnbr(debug1); //debug
						ft_putstr("\npos y : "); //debug
						ft_putnbr(debug2); //debug
					ft_putstr("\npos x : "); //debug
					ft_putnbr(debug1); //debug
					ft_putstr("\npos y : "); //debug
					ft_putnbr(debug2); //debug
				}
				//i++;
				ft_putendl("\n\n-------HERE-------\n"); //debug
			}
		}
		else if (carre[a + x][b + y] != '.')
		{
			ft_putstr("\nposition carre prise\n");
			if (carre[a][b + 1])
				b++;
			else
			{
				a++;
				b = 0;
				x = 0;
				y = 0;
				hashtag = 0;
			}
		}
	}
	if (hashtag == 4)
	{
		pos->x = a;
		pos->y = b;
	}
	return (hashtag == 4 ? 1 : 0);
}

int		ft_placement(t_elem const *piece, char **carre, int cote)
{
	int			x;
	int			y;
	t_elem		*tmp;
	t_pos		pos;

	x = 0;
	y = 0;
	tmp = (t_elem *)piece;
	pos.x = 0;
	pos.y = 0;
	while (carre[x] && carre[x][y] != '\0' && tmp->content)
	{
		ft_putstr("\n ------- \n (ft placement) - Carre a remplir : \n"); //debug
		ft_affres(carre); //debug
		ft_putstr("\n"); //debug
		if (carre[x][y] == '\0' || (carre[x][y] != '.' && carre[x][y + 1] == '\0'))
		{
			x++;
			y = 0;
		}
		else if (carre[x][y] != '.' && carre[x][y + 1] != '\0')
			y++;
		else
		{
			ft_putstr("\n-----------------\n(ft placement) - Piece a placer\n----------------\n\n"); //debug
			ft_putstr(tmp->content); //
			if (ft_verifdispo(carre, tmp, &pos, cote))
			{
				ft_putstr("\n\n>> Emplacement disponible"); //debug
				ft_putstr("\n\n---------------------------------------\n");
				ft_putstr("\npos.x : ");
				ft_putnbr(pos.x);
				ft_putstr("\npos.y : ");
				ft_putnbr(pos.y);
				ft_putstr("\n\n---------------------------------------\n");
				ft_putpiece(carre, tmp->content, pos, cote);
				ft_putstr("\n"); //debug
				if (tmp->next == NULL)
				{
					ft_putstr("Toutes les pieces sont placees"); //debug
					return (1);
				}
				if (ft_placement(tmp->next, carre, cote))
				{
					ft_putstr("\nDONE\n"); //debug
					return (1);
				}
			}
		}
	}
	ft_putstr("\n\n-------------------------------");//debug
	ft_putstr("\n-------------retour------------\n");//debug
	ft_putstr("-------------------------------\n\n\n\n");//debug
	if(tmp->prev != NULL)
		carre = ft_erase(tmp->prev->lettre, carre);
	return (0);
}

void	ft_resolution(t_dbllist *list_piece, int nb_pieces)
{
	int			cote;
	char		**res;

	cote = ft_sqrtfillit(4 * nb_pieces);
	res = ft_carrevide(cote);
	while (ft_placement(list_piece->head, res, cote) == 0)
	{
		ft_putstr("impossible");
		cote++;
		if (res)
			ft_memdel((void **)res);
		res = ft_carrevide(cote);
	}
	ft_putstr("\nRES : \n"); //debug
	ft_affres(res);
}
