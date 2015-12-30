/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/07 14:31:47 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/29 12:43:20 by kvignau          ###   ########.fr       */
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
	unsigned int			height;
	unsigned int			width;
	char				lettre;
	struct s_elem		*prev;
	struct s_elem		*next;
}						t_elem;

typedef	struct			s_dbllist
{
	size_t				length;
	struct s_elem		*tail;
	struct s_elem		*head;
}						t_dbllist;

typedef struct			s_pos
{
	int					x;
	int					y;
}						t_pos;

int						ft_validite_piece(char *buf);
int						ft_replace(char *buf, int *hashtag, char lettre);
int						ft_validite_char(char *buf, int *fin, char lettre);
int						ft_validite_fichier(char *fichier,\
						t_dbllist **list_piece, int ret, int *nb_pieces);
void					ft_lstdbladd(t_dbllist **list, void *content,\
						size_t cont_size, char lettre);
t_dbllist				*ft_lstdblnew(void);
void					ft_enregistrement(char *buf, t_dbllist **list_piece,\
						char lettre);
void					ft_putlsthead(t_dbllist *list);
void					ft_putlsttail(t_dbllist *list);
void					ft_lstdbldel(t_dbllist **list);
int						ft_sqrtfillit(int n);
void					ft_resolution(t_dbllist *listpiece, int nb_pieces);
void					ft_affres(char **res);
char					**ft_carrevide(int c);
char					**ft_erase(char lettre, char **carre);
int						ft_placement(t_elem const *piece, char **carre,\
						int cote);
void					ft_putpiece(char **carre, char *piece, t_pos pos);
int						ft_verifdispo(const char **carre, const t_elem *piece, t_pos pos, int cote);
void					ft_move(int *i, int *x, int *y);

#endif
