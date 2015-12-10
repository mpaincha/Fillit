/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:27:52 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/10 15:41:04 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		t_dbllist	*list_piece;

		list_piece = ft_lstdblnew();
		if (ft_validite_fichier(av[1], &list_piece) == -1)
		{
			//on peut free les malloc ici comme ca on free directement pour tous les cas d'erreur
			ft_putstr("error\n");
		}
		else
		{
			ft_putstr("nikel");
		}
	}
	return (0);
}
