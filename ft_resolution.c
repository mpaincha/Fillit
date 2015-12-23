/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:37:37 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/23 12:25:53 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//verif si carre parfait strictement plus grand que 4 de cote :i
//WARNING FAIRE LE CAS OU LE CARRE PARFAIT EST PLUS PETIT que 4 DE COTES 

//verif si carre parfait strictement plus grand que 4 de cote :

void	ft_move(int	*i, int *x, int *y)
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
}

int		ft_verifdispo(char **carre, t_elem	*piece, t_pos *pos)
{
	int		i;
	int		hashtag;
	int		a;
	int		b;
	char	*piece1;
	int		y;
	int		x;

	piece1 = (char *)(piece->content);
	a = 0;
	b = 0;
	i = 0;
	y = 0;
	x = 0;
	hashtag = 0;
	while (carre[a] && carre[a][b] && hashtag != 4)
	{
		ft_putstr("\nBOUCLE 1 : ");
		ft_putstr("\ni : ");
		ft_putnbr(i);
		ft_putstr("\nx : ");
		ft_putnbr(x);
		ft_putstr("\ny : ");
		ft_putnbr(y);
		ft_putstr("\nb :"); //debug
		ft_putnbr(b); //debug
		ft_putstr("\ni :"); //debug
		ft_putnbr(i); //debug
		ft_putstr("\na :"); //debug
		ft_putnbr(a); //debug
		ft_putstr("\nb :"); //debug
		ft_putnbr(b); //debug
			ft_putstr("\n>>carre a b  :"); //debug
			ft_putchar(carre[a][b]);
		if (carre[a + x][b + y] == '\0')
		{
			ft_putstr("\n>>Search in a new line :"); //debug
			a++;
			b = 0;
		}
		else if (carre[a + x][b + y] && carre[a + x][b + y] != '.' && carre[a][b + 1])
			b++;
	//	else if (carre[a][b] && carre[a][b] != '.' && carre[a][b + 1] == '\0')
	//	{
	//		a++;
	//		b = 0;
	//	}
		else
		{
			while (i < 16 && hashtag != 4) //&& carre[a + x] && carre[a + x][b + y])
			{
				if (piece1[i] != '.' && (carre[a + x] == '\0' || carre[a + x][b + y] == '\0'))
				{
					break ;
				}
				while (i < 16 && hashtag != 4 && carre[a + x] && carre[a + x][b + y]
					&& carre[a + x][b + y] == '.')
				{
					ft_putstr("\nBOUCLE 2 : ");
					if (hashtag == 0 && piece1[i] == '.')
						break ;
					else if (piece1[i] == '.')
					{
						ft_putstr("\npiece1[i] = . : ");
						ft_putstr("\ni : ");
						ft_putnbr(i);
						ft_move(&i, &x, &y);
						ft_putstr("\nx : ");
						ft_putnbr(x);
						ft_putstr("\ny : ");
						ft_putnbr(y);
						ft_putstr("\ni : ");
						ft_putnbr(i);
					}
					else
					{
						hashtag++;
						ft_putstr("\nBOUCLE 3 : ");
						ft_putstr("\nposition ok\nnb hashtag : ");
						ft_putnbr(hashtag);
						ft_putstr("\ni : ");
						ft_putnbr(i);
						ft_putstr("\nx : ");
						ft_putnbr(x);
						ft_putstr("\ny : ");
						ft_putnbr(y);
						ft_move(&i, &x, &y);
					}
				}
				while (i < 16 && piece1[i] == '.' && hashtag != 4)
				{
					ft_putstr("\nBOUCLE 4 : ");
					ft_move(&i, &x, &y);
					ft_putstr("\ni : ");
					ft_putnbr(i);
					ft_putstr("\nx : ");
					ft_putnbr(x);
					ft_putstr("\ny : ");
					ft_putnbr(y);
				}
				i++;
				ft_putendl("here");
			}
		}
	}
	if (hashtag == 4)
	{
		pos->x = a;
		pos->y = b;
		ft_putstr("\npos->x : ");
		ft_putnbr(pos->x);
		ft_putstr("\npos->y : ");
		ft_putnbr(pos->y);
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
	while (carre[x][y] != '\0' && carre[x] && tmp->content)
	{
		ft_putstr("\n carre a remplir : \n"); //debug
		ft_affres(carre); //debug
		if (carre[x][y] == '\0')
		{
			x++;
			y = 0;
		}
		else if (carre[x][y] != '.')
			y++;
		else
		{
			ft_putstr("\n-----------------\n FT_PLACEMENT -- piece a placer :\n"); //debug
			ft_putstr(tmp->content); //
			if (ft_verifdispo(carre, tmp, &pos))
			{
				ft_putstr("\n\n>> Emplacement disponible"); //debug
				ft_putstr("\n\n---------------------------------------\n");
				ft_putstr("\npos.x : ");
				ft_putnbr(pos.x);
				ft_putstr("\npos.y : ");
				ft_putnbr(pos.y);
				ft_putstr("\n\n---------------------------------------\n");
				ft_putpiece(carre, tmp->content, pos);
				ft_putstr("\nNew carre :\n"); //debug
				ft_affres(carre); //debug
				ft_putstr("\n"); //debug
				if (tmp->next == NULL)
				{
					ft_putstr("OUEP"); //debug
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
