/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:37:37 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/23 15:20:35 by mpaincha         ###   ########.fr       */
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
	int		x;
	int		y;
	int		x1;
	int		y1;
	int		hash;
	char	*piece1;
	int		i;

	x = 0;
	y = 0;
	x1 = 0;
	y1 = 0;
	hash = 0;
	i = 0;
	piece1 = (char *)(piece->content);
	while (piece1[i] && carre[x + x1][y + y1])
	{
		if (hash == 0 && piece1[i] == '.')
		{
			i++;
		}
		else if (piece1[i] == '.')
		{
			ft_move(&i, &x, &y);
			i++;
		}
		if (piece1[i] != '.' && carre[x][y] == '.')
		{
			hash++;
			ft_move(&i, &x, &y);
			i++;
		}
		else
		{
			i = 0;
			x++;
			y++;
			x1 = 0;
			y1 = 0;;
		}
	}
	if (hash == 4)
	{
		pos->x = x;
		pos->y = y;
		return (1);
	}
	else
		return (0);
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
		ft_putstr("\n ------- \n Carre a remplir : \n"); //debug
		ft_affres(carre); //debug
		ft_putstr("\n"); //debug
		if (carre[x][y] == '\0')
		{
			x++;
			y = 0;
		}
		else if (carre[x][y] != '.')
			y++;
		else
		{
			ft_putstr("\n-----------------\nFT_PLACEMENT -- piece a placer\n----------------\n\n"); //debug
			ft_putstr(tmp->content); //debug
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
