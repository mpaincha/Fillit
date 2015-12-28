/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:37:37 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/28 17:39:53 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_move(int *i, int *x, int *y)
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
		*y = *y + 1;
		*x = 0;
	}
	*i = *i + 1;
}

int		ft_verifdispo(char **carre, t_elem *piece, t_pos *pos)
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
	while (carre[a + x] && carre[a + x][b + y] && hashtag != 4)
	{
		if (piece1[0] == '.')
			i = 0;
		while (i < 16 && hashtag != 4 && carre[a + x])
		{
			if (piece1[i] != '.' && carre[a + x] && carre[a + x][b + y] == '\0')
			{
				i = 0;
				if (carre[a + x + 1])
				{
					a++;
					b = 0;
					x = 0;
					y = 0;
					hashtag = 0;
				}
				else
					return (0);
				break ;
			}
			if (carre[a + x] && carre[a + x][b + y] && carre[a + x][b + y] != '.' && piece1[i] == '.')
				ft_move(&i, &x, &y);
			if (carre[a + x][b + y] && carre[a + x][b + y] == '.')
			{
				if (hashtag == 0 && piece1[i] == '.')
				{
					if (i != 0)
						i++;
					else
						ft_move(&i, &x, &y);
					break ;
				}
				else if (piece1[i] == '.')
					ft_move(&i, &x, &y);
				else
				{
					hashtag++;
					ft_move(&i, &x, &y);
				}
			}
			if (i < 16 && piece1[i] == '.' && hashtag != 4 && carre[a + x] && carre[a + x][b + y] == '\0')
				ft_move(&i, &x, &y);
			if (piece1[i] != '.' && carre[a + x] && carre [a + x][b + y] && carre[a + x][b + y] != '.')
				break ;
		}
		if (piece1[i] != '.' && carre[a + x] && carre[a + x][b + y] && carre[a + x][b + y] != '.')
		{
			if (piece1[0] == '.')
				i = 1;
			else
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
		}
	}
	if (hashtag == 4)
	{
		pos->x = a;
		pos->y = b;
	}
	return (hashtag == 4 ? 1 : 0);
}

int		ft_pluspetit(char **carre, t_pos *pos, t_elem *piece)
{
	if (pos->y + 1 == '\0' && pos->x + 1 == '\0')
		return (1);
	if (carre[pos->x][pos->y] != '.')
	{
		if (pos->y + 1 == '\0')
		{
			pos->y = 0;
			pos->x = pos->x + 1;
		}
		else
			pos->y = pos->y + 1;
		return (ft_pluspetit(carre, pos, piece->next));
	}
	while (piece->content)
	{
		if (ft_verifdispo(carre, piece, pos))
		{
			ft_putpiece(carre, piece->content, *pos);
			if (pos->y + 1 == '\0')
			{
				pos->y = 0;
				pos->x = pos->x + 1;
			}
			else
				pos->y = pos->y + 1;
			if (ft_pluspetit(carre, pos, piece->next))
				return (1);
		}
		piece = piece->next;
	}
	ft_erase(piece->prev->lettre, carre);
	return (0);
}

/*int		ft_placement(t_elem const *piece, char **carre, int cote)
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
		if (carre[x][y] == '\0' || (carre[x][y] != '.' && carre[x][y + 1] == '\0'))
		{
			x++;
			y = 0;
		}
		else if (carre[x][y] != '.' && carre[x][y + 1] != '\0')
			y++;
		else
		{
			if (ft_verifdispo(carre, tmp, &pos))
			{
				ft_putpiece(carre, tmp->content, pos);
				if (tmp->next == NULL)
					return (1);
				if (ft_placement(tmp->next, carre, cote))
					return (1);
			}
			else
				return (0);
		}
	}
	ft_putstr("\n-------------retour------------\n");//debug
	if(tmp->prev != NULL)
		carre = ft_erase(tmp->prev->lettre, carre);
	return (0);
}
*/

void	ft_resolution(t_dbllist *list_piece, int nb_pieces)
{
	int			cote;
	char		**res;
	t_pos		pos;

	pos.x = 0;
	pos.y = 0;
	cote = ft_sqrtfillit(4 * nb_pieces);
	res = ft_carrevide(cote);
	while (ft_pluspetit(res, &pos, list_piece->head))//ft_placement(list_piece->head, res, cote) == 0)
	{
		cote++;
		if (res)
			ft_memdel((void **)res);
		res = ft_carrevide(cote);
	}
	ft_putstr("\nRES : \n"); //debug
	ft_affres(res);
}
