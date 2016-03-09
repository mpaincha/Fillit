/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:27:52 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/30 18:02:15 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_dbllist	*list_piece;
	int			ret;
	int			nb_pieces;

	ret = 0;
	nb_pieces = 0;
	if (ac == 2)
	{
		list_piece = ft_lstdblnew();
		ret = ft_valid_fichier(av[1], &list_piece, ret, &nb_pieces);
		if (ret == 0)
			return (0);
		else if (ret < 0)
		{
			ft_putstr("error\n");
			if (ret == -2)
				ft_lstdbldel(&list_piece);
		}
		else
			ft_resolution(list_piece, nb_pieces);
	}
	else
		ft_putstr("error\n");
	return (0);
}
