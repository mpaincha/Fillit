/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/04 13:35:07 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/06 15:03:57 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int		ft_replace(char *buf, int *hashtag, char letter)
{
	int		i;
	int		point;

	point = 0;
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (-1);
		else if (buf[i] == '.')
			point++;
		else if (buf[i] == '#')
		{
			buf[i] = letter;
			*hashtag = *hashtag + 1;
		}
		i++;
	}
	if (point != 12 || *hashtag != 4)
		return (-1);
	return (1);
}

static int		ft_valid_piece(char *buf)
{
	int		i;
	int		contact;

	contact = 0;
	i = 0;
	while (i < 20)
	{
		if (buf[i] == '#' && buf[i + 1] == '#')
			contact++;
		if (buf[i] == '#' && buf[i + 5] == '#')
			contact++;
		i++;
	}
	if (contact < 3)
		return (-1);
	return (1);
}

static int		ft_valid_char(char *buf, int *end, char letter)
{
	int		i;
	int		hashtag;
	int		point;

	point = 0;
	hashtag = 0;
	i = 4;
	while (i < 20)
	{
		if (buf[i] != '\n')
			return (-1);
		i = i + 5;
	}
	if (buf[20] == '\0')
		*end = *end + 1;
	if (buf[20] != '\n' && buf[20] != '\0')
		return (-1);
	if (ft_valid_piece(buf) == -1)
		return (-1);
	if (ft_replace(buf, &hashtag, letter) == -1 || hashtag != 4)
		return (-1);
	return (1);
}

int				ft_valid_fichier(char *fichier, t_dbllist **list_piece, int ret,
				int *nb_pieces)
{
	char	buf[22];
	int		fd;
	int		end;
	char	letter;

	letter = 'A';
	end = 0;
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if (ft_valid_char(buf, &end, letter) == -1)
			return (-1);
		else
			ft_registry(buf, list_piece, letter);
		*nb_pieces = *nb_pieces + 1;
		letter++;
	}
	if (close(fd) == -1 || end != 1 || *nb_pieces > 26 || *nb_pieces == 0)
		return (-2);
	return (1);
}
