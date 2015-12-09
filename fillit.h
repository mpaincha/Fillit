/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:31:47 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/09 16:27:06 by mpaincha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "Libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct			s_dbllist
{
	void				*content;
	size_t				content_size;
	size_t				nb_elem;
	struct s_dbllist	*prev;
	struct s_dbllist	*next;
}						t_dbllist;

int						ft_validite_piece(char *buf);
int						ft_validite_char(char *buf, int	*fin);
int						ft_validite_fichier(char *fichier, t_dbllist **list_piece);
void					ft_lstdbladd(t_dbllist **alst, t_dbllist *new);
t_dbllist				*ft_lstdblnew(void const *content, size_t content_size);
void					ft_enregistrement(char *buf, t_dbllist **list_piece);

#endif
