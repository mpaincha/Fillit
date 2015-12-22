/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:44:39 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/22 18:01:29 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putpiece(char **carre, char *piece, t_pos pos)
{
	int		i;
	int		j;
	int		a;
	int		pose;

	i = 0;
	j = 0;
	a = 0;
	pose = 0;
	ft_putstr("\nPUT PIECE:");
	while (piece[i] && pose < 4)
	{
		if (piece[i] != '.')
		{
			ft_putstr("\nPUT PIECE:");
			carre[pos.x + a][pos.y + j] = piece[i];
			pose++;
			if (i >= 12)
			{
				j = i - 12;
				a = 3;
			}
			else if (i >= 8)
			{
				j = i - 8;
				a = 2;
			}
			else if (i >= 4)
			{
				j = i - 4;
				a = 1;
			}
			else
			{
				j = i + 1;
				a = 0;
			}
				ft_putstr("\n-------------------------------\n");
				ft_putstr("\nvaleur de posX + a : ");
				ft_putnbr(pos.x + a);
				ft_putstr("\nvaleur de posY + j: ");
				ft_putnbr(pos.y + j);
				ft_putstr("\nvaleur de i : ");
				ft_putnbr(i);
				ft_putstr("\n");
				ft_putstr("\n-------------------------------\n");
		}
		i++;
	}
	ft_putstr("\nNEW CARRE:");
	ft_affres(carre);
}

char	**ft_erase(char lettre, char **carre)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (carre[i] != NULL)
	{
		while (carre[i][j] != '\0' && carre[i][j] == lettre)
		{
			carre[i][j] = '.';
			j++;
		}
		i++;
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
