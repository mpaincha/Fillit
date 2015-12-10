/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verifications.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/10 11:03:32 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/10 17:24:32 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_validite_piece(char *buf)
{
	int		i;

	i = 0;
	while (i < 20)
	{
		if (buf[i] == '#' && buf[i - 1] != '#' && buf[i + 1] != '#'
					&& buf[i - 5] != '#' && buf[i + 5] != '#')
			return (-1);
		i++;
	}
	return (1);
}

int		ft_validite_char(char *buf, int	*fin)
{
	int		i;
	int		hashtag;

	hashtag = 0;
	i = 4;
	while (i < 20)
	{
		if (buf[i] != '\n')
			return (-1);
		i = i + 5;
	}
	if (buf[20] == '\0')
		*fin = *fin + 1;
	if (buf[20] != '\n' && buf[20] != '\0')
		return (-1);
	i = 0;
	while (buf[i] != '\0')
	{
		if (buf[i] != '.' && buf[i] != '#' && buf[i] != '\n')
			return (-1);
		if (buf[i] == '#')
			hashtag++;
		i++;
	}
	if (hashtag != 4 || ft_validite_piece(buf) == -1)
		return (-1);
	return (1);
}

int		ft_validite_fichier(char *fichier, t_dbllist **list_piece)
{
	char	buf[22];
	int		fd;
	int		ret;
	int		nb_pieces;
	int		fin;

	nb_pieces = 0;
	fin = 0;
	fd = open(fichier, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		if (ft_validite_char(buf, &fin) == -1)
			return (-1);
		else
			ft_enregistrement(buf, list_piece);
		nb_pieces++;
	}
	if (close(fd) == -1)
		return (-2);
	if (fin != 1)
	{
		return (-2);
	}
	if (nb_pieces > 26 || nb_pieces == 0)
	{
		return (-2);
	}
	return (1);
}
