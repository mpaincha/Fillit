/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:27:52 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/10 17:33:28 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	t_dbllist	*list_piece;
	int			ret;

	if (ac == 2)
	{
		list_piece = ft_lstdblnew();
		ret = ft_validite_fichier(av[1], &list_piece);
		if (ret < 0)
		{
			ft_putstr("error\n");
			ft_putlsthead(list_piece);//debug
			if (ret == -2)
				ft_dbldel(&list_piece);
			ft_putlsthead(list_piece);//debug
		}
		else
		{
			ft_putstr("nikel");
		}
	}
	return (0);
}
