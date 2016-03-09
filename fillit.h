/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:31:47 by mpaincha          #+#    #+#             */
/*   Updated: 2016/01/04 10:45:04 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "Libft/libft.h"
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef	struct			s_elem
{
	void				*content;
	unsigned int		height;
	unsigned int		width;
	char				letter;
	struct s_elem		*prev;
	struct s_elem		*next;
}						t_elem;

typedef	struct			s_dbllist
{
	struct s_elem		*tail;
	struct s_elem		*head;
}						t_dbllist;

typedef struct			s_pos
{
	int					x;
	int					y;
}						t_pos;

int						ft_valid_fichier(char *fichier,\
						t_dbllist **list_piece, int ret, int *nb_pieces);
void					ft_lstdbladd(t_dbllist **list, void *content,\
						size_t cont_size, char letter);
t_dbllist				*ft_lstdblnew(void);
void					ft_registry(char *buf, t_dbllist **list_piece,\
						char letter);
void					ft_lstdbldel(t_dbllist **list);
int						ft_sqrtfillit(int n);
void					ft_resolution(t_dbllist *listpiece, int nb_pieces);
void					ft_showres(char **res);
char					**ft_emptysquare(int c);
char					**ft_erase(char letter, char **square);
void					ft_move(int *i, int *x, int *y);
void					ft_putpiece(char **square, char *piece, t_pos pos);

#endif
