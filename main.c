/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:27:52 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/11 11:54:07 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_dbllist	*list_piece;
	int			ret;
	char		*res;
	int			nb_pieces;

	ret = 0;
	nb_pieces = 0;
	if (ac == 2)
	{
		list_piece = ft_lstdblnew();
		ret = ft_validite_fichier(av[1], &list_piece, ret, &nb_pieces);
		if (ret < 0)
		{
			ft_putstr("error\n");
			if (ret == -2)
			{
				ft_lstdbldel(&list_piece);
				free(list_piece);
			}
		}
		else
		{
			ft_putstr("nikel"); //debug
			ft_putnbr(ft_tailledbt(nb_pieces));
		}
	}
	return (0);
}
