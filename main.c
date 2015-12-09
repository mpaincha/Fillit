/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 15:27:52 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/09 15:03:53 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		main(int ac, char **av)
{
	if (ac == 2)
	{
		t_dbllist	*list_piece;

		list_piece = NULL;
		if (ft_validite_fichier(av[1], &list_piece) == -1)
			ft_putstr("error\n");
		else
		{
			ft_putstr("nikel");
			while (list_piece->next)
			{
				ft_putstr(" \n");
				ft_putstr((char *)list_piece->content);
				list_piece = list_piece->next;
			}
			// algo test pos.
		}
	}
	return (0);
}
