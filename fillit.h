/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:31:47 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/08 14:06:06 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "Libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct			s_doublelist
{
	void				*content;
	size_t				content_size;
	size_t				nb_elem;
	struct s_doublelist	*prev;
	struct s_doublelist	*next;
}						t_doublelist;

int						ft_validite_piece(char *buf);
int						ft_validite_char(char *buf);
int						ft_validite_fichier(char *fichier);
void					ft_lstdoubleadd(t_doublelist **alst, t_doublelist *new);
t_doublelist			*ft_lstdoublenew(void const *content, size_t content_size, size_t nb_elem);
void					ft_enregistrement(char *buf);

#endif
