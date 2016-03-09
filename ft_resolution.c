/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:37:37 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/04 10:49:35 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_checkvacant(const char **carre, const t_elem *piece,
				t_pos pos, int side)
{
	const char	*content;
	int			x;
	int			y;

	x = 0;
	content = (const char *)piece->content;
	if (pos.x + (piece->height - 1) >= (unsigned int)side ||
		pos.y + (piece->width - 1) >= (unsigned int)side)
		return (0);
	else
	{
		while ((unsigned int)x < piece->height)
		{
			y = 0;
			while ((unsigned int)y < piece->width)
			{
				if (carre[pos.x + x][pos.y + y] != '.' &&
					content[x * 4 + y] != '.')
					return (0);
				y++;
			}
			x++;
		}
	}
	return (1);
}

static int		ft_research(char **carre, t_elem const *piece, int side)
{
	t_elem		*tmp;
	t_pos		pos;

	tmp = (t_elem *)piece;
	pos.x = 0;
	while (carre[pos.x])
	{
		pos.y = 0;
		while (carre[pos.x][pos.y])
		{
			if (ft_checkvacant((const char **)carre, tmp, pos, side))
			{
				ft_putpiece(carre, tmp->content, pos);
				if (tmp->next == NULL)
					return (1);
				if (ft_research(carre, tmp->next, side))
					return (1);
				carre = ft_erase(tmp->letter, carre);
			}
			pos.y = pos.y + 1;
		}
		pos.x = pos.x + 1;
	}
	return (0);
}

void			ft_move(int *i, int *x, int *y)
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

void			ft_resolution(t_dbllist *list_piece, int nb_pieces)
{
	int			side;
	char		**res;
	t_pos		pos;

	pos.x = 0;
	pos.y = 0;
	side = ft_sqrtfillit(4 * nb_pieces);
	res = ft_emptysquare(side);
	while (ft_research(res, list_piece->head, side) == 0)
	{
		side++;
		if (res)
			ft_memdel((void **)res);
		res = ft_emptysquare(side);
	}
	ft_showres(res);
}
