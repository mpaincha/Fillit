/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:37:37 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/22 18:01:27 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

//verif si carre parfait strictement plus grand que 4 de cote :i
//WARNING FAIRE LE CAS OU LE CARRE PARFAIT EST PLUS PETIT que 4 DE COTES 

//verif si carre parfait strictement plus grand que 4 de cote :

static	void	ft_move(int	*i, int *x, int *y)
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
	int		j;
	int		a;
	char	*piece1;
	int		y;
	int		x;

	piece1 = (char *)(piece->content);
	j = 0;
	i = 0;
	a = 0;
	y = 0;
	x = 0;
	hashtag = 0;
	while (carre[a] && carre[a][j] && hashtag != 4)
	{
		ft_putstr("\nBOUCLE 1 : ");
		ft_putstr("\ni : ");
		ft_putnbr(i);
		ft_putstr("\nx : ");
		ft_putnbr(x);
		ft_putstr("\ny : ");
		ft_putnbr(y);
		ft_putstr("\nj :"); //debug
		ft_putnbr(j); //debug
		ft_putstr("\ni :"); //debug
		ft_putnbr(i); //debug
		if (carre[a][j] == '\0')
		{
			a++;
			j = 0;
		}
		else if (carre[a][j] != '.')
			j++;
		else
		{
			while (i < 16 && carre[a + x] && carre[a + x][j + y]
					&& carre[a + x][j + y] == '.')
			{
				if (hashtag == 0 && piece1[i] == '.')
					i++;
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
					i++;
				}
				else
				{
					hashtag++;
					ft_putstr("\nBOUCLE 2 : ");
					ft_putstr("\nposition ok\nnb hashtag : ");
					ft_putnbr(hashtag);
					ft_putstr("\ni : ");
					ft_putnbr(i);
					ft_putstr("\nx : ");
					ft_putnbr(x);
					ft_putstr("\ny : ");
					ft_putnbr(y);
					ft_move(&i, &x, &y);
					i++;
				}
			}
			if (hashtag != 4)
			{
				i = 0;
				hashtag = 0;
			}
		}
	}
	if (hashtag == 4)
	{
		pos->y = j;
		pos->x = a;
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
			ft_putstr("\n piece a placer :\n"); //debug
			if (ft_verifdispo(carre, tmp, &pos))
			{
				//ft_putstr("\n Emplacement disponible"); //debug
				ft_putstr("\n\n\n\n---------------------------------------\n");
				ft_putnbr(pos.x);
				ft_putnbr(pos.x);
				ft_putstr("\n\n\n\n---------------------------------------\n");
				ft_putpiece(carre, tmp->content, pos);
				ft_putstr("\nnew carre :\n"); //debug
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
	//carre[pos] = '.';
	ft_putstr("\n\n\n\n\n-------------------------------");//debug
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
