/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_actions.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/22 15:44:39 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/30 17:11:20 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_putpiece(char **square, char *piece, t_pos pos)
{
	int		i;
	int		a;
	int		b;
	int		put;

	i = 0;
	a = 0;
	b = 0;
	put = 0;
	while (piece[i] && put < 4)
	{
		if (piece[i] != '.')
		{
			square[pos.x + a][pos.y + b] = piece[i];
			put++;
			ft_move(&i, &a, &b);
		}
		else
			ft_move(&i, &a, &b);
	}
}

char	**ft_erase(char letter, char **square)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (square[i] != NULL)
	{
		while (square[i][j])
		{
			if (square[i][j] == letter)
				square[i][j] = '.';
			j++;
		}
		i++;
		j = 0;
	}
	return (square);
}

char	**ft_emptysquare(int c)
{
	int		i;
	int		j;
	char	**square;
	char	*col;

	i = 0;
	square = (char **)malloc(sizeof(char *) * (c + 1));
	if (square == NULL)
		return (NULL);
	while (i < c)
	{
		j = 0;
		col = (char *)malloc(sizeof(char) * (c + 1));
		if (col == NULL)
		{
			free(square);
			return (NULL);
		}
		while (j < c)
			col[j++] = '.';
		col[j] = '\0';
		square[i++] = col;
	}
	square[i] = NULL;
	return (square);
}

void	ft_showres(char **res)
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
