/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:44:39 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/29 11:46:18 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putpiece(char **carre, char *piece, t_pos pos)
{
	int		i;
	int		a;
	int		b;
	int		pose;

	i = 0;
	a = 0;
	b = 0;
	pose = 0;
	while (piece[i] && pose < 4)
	{
		if (piece[i] != '.')
		{
			carre[pos.x + a][pos.y + b] = piece[i];
			pose++;
			ft_move(&i, &a, &b);
		}
		else
			ft_move(&i, &a, &b);
	}
}

char	**ft_erase(char lettre, char **carre)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (carre[i] != NULL)
	{
		while (carre[i][j])
		{
			if (carre[i][j] == lettre)
				carre[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
	return (carre);
}

char	**ft_carrevide(int c)
{
	int		i;
	int		j;
	char	**carre;
	char	*col;

	i = 0;
	j = 0;
	carre = (char **)malloc(sizeof(char *) * (c + 1));
	if (carre == NULL)
		return (NULL);
	while (i < c)
	{
		col = (char *)malloc(sizeof(char) * (c + 1));
		if (col == NULL)
		{
			free(carre);
			return (NULL);
		}
		while (j < c)
		{
			col[j++] = '.';
		}
		col[j] = '\0';
		carre[i] = col;
		j = 0;
		i++;
	}
	carre[i] = NULL;
	return (carre);
}

void	ft_affres(char **res)
{
	int		x;

	x = 0;
	while (res[x])
	{
		ft_putstr(res[x]);
		ft_putchar('\n');
		x++;
	}
}
