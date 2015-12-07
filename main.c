/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:27:52 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/07 18:46:20 by mpaincha         ###   ########.fr       */
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

int		ft_validite_char(char *buf)
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
	if (buf[20] != '\n' && buf[20] != '\0')
		return (-1);
	i = 0;
	while (buf[i] != '\0')
	{
		if ((buf[i] != '.' && buf[i] != '#' && buf[i] != '\n') || hashtag > 4)
			return (-1);
		if (buf[i] == '#')
			hashtag++;
		i++;
	}
	if (ft_validite_piece(buf) == -1)
		return (-1);
	return (1);
}

int		ft_validite_fichier(char *liste_pieces)
{
	char	buf[22];
	int		fd;
	int		ret;
	int		nb_pieces;

	nb_pieces = 0;
	fd = open(liste_pieces, O_RDONLY);
	if (fd == -1)
		return (-1);
	while ((ret = read(fd, buf, 21)))
	{
		buf[ret] = '\0';
		ft_putstr(buf);
		ft_putnbr(ft_validite_char(buf));
		ft_putchar('\n');
		if (ft_validite_char(buf) == -1)
			return (-1);
		nb_pieces++;
	}
	if (nb_pieces > 26)
		return (-1);
	ft_putstr("fichier valide");
	ft_putchar('\n');
	return (1);
}

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		if (ft_validite_fichier(av[1]) == -1)
			ft_putstr("error\n");
		else
			ft_putstr("nikel");
	}
	return (0);
}
