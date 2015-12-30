/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:37:37 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/30 17:29:56 by mpaincha         ###   ########.fr       */
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

int		ft_verifdispo(const char **carre, const t_elem *piece, t_pos pos,
		int cote)
{
	const char	*content;
	int			x;
	int			y;

	x = 0;
	content = (const char *)piece->content;
	if (pos.x + (piece->height - 1) >= (unsigned int)cote ||
		pos.y + (piece->width - 1) >= (unsigned int)cote)
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

int		ft_pluspetit(char **carre, t_elem const *piece, int cote)
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
			if (ft_verifdispo((const char **)carre, tmp, pos, cote))
			{
				ft_putpiece(carre, tmp->content, pos);
				if (tmp->next == NULL)
					return (1);
				if (ft_pluspetit(carre, tmp->next, cote))
					return (1);
				carre = ft_erase(tmp->lettre, carre);
			}
			pos.y = pos.y + 1;
		}
		pos.x = pos.x + 1;
	}
	return (0);
}

void	ft_resolution(t_dbllist *list_piece, int nb_pieces)
{
	int			cote;
	char		**res;
	t_pos		pos;

	pos.x = 0;
	pos.y = 0;
	cote = ft_sqrtfillit(4 * nb_pieces);
	res = ft_carrevide(cote);
	while (ft_pluspetit(res, list_piece->head, cote) == 0)
	{
		cote++;
		if (res)
			ft_memdel((void **)res);
		res = ft_carrevide(cote);
	}
	ft_affres(res);
}
