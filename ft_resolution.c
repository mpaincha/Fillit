/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:37:37 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/22 12:21:21 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//REGARDER QUAND LA PIECE NES PAS TESTE A PARTIR DE LA POSITION POS 0)
/*void	ft_putpiece(char **carre, char *piece, t_pos *pos)
  {
  int		i;
  int		pose;
  int		j;

  i = 0;
  pose = 0;
  j = pos->ini;
  ft_putstr("\nPUT PIECE:");
  ft_putstr("\npos ini:");
  ft_putnbr(pos->ini);
  while (piece[i] && carre[j])
  {
  if (piece[i] != '.')
  {
  if (carre[j] == '.')
  {
  ft_putstr("\nPUT PIECE:");
  carre[j] = piece[i];
  ft_putstr("\nj avant:");
  ft_putnbr(j);
  j = ft_newpos(j, pos);
  ft_putstr("\nj apres");
  ft_putnbr(j);
  pose++;
  }
  else
  return ;
  }
  else if (pose != 0)
  j = ft_newpos(j, pos);
  i++;
  }
  ft_putstr("\nNEW CARRE:");
  ft_putstr(carre);
  }*/

/*int		ft_newpos(int j, t_pos *pos)
  {
  int		jnew;

  jnew = j;
  if (j == pos->max1)
  jnew = pos->min1;
  else if (j == pos->max2)
  jnew = pos->min2;
  else if (j == pos->max3)
  jnew = pos->min3;
  else
  jnew++;
  ft_putstr("\nNEWPOS:");
  ft_putnbr(jnew);
  return (jnew);
  }

  void	ft_structpos(t_pos *pos, int cote)
  {
  pos->max1 = pos->ini + 3;
  pos->min1 = pos->ini + cote;
  pos->max2 = pos->min1 + 3;
  pos->min2 = pos->min1 + cote;
  pos->max3 = pos->min2 + 3;
  pos->min3 = pos->min2 + cote;
  pos->max4 = pos->min3 + 3;

  ft_putstr("\npos ini:");
  ft_putnbr(pos->ini);
  ft_putstr("\npos max1:");
  ft_putnbr(pos->max1);
  ft_putstr("\npos min1:");
  ft_putnbr(pos->min1);
  ft_putstr("\npos max2:");
  ft_putnbr(pos->max2);
  ft_putstr("\npos min2:");
  ft_putnbr(pos->min2);
  ft_putstr("\npos max3:");
  ft_putnbr(pos->max3);
  ft_putstr("\npos min3:");
  ft_putnbr(pos->min3);
  ft_putstr("\npos max4:");
  ft_putnbr(pos->max4);

  }


  int		ft_testmax(int cote, t_pos *pos, char *piece)
  {
  int	i;

  i = 2;
  while (pos->ini > cote)
  {
  cote *= i;
  i++;
  }
  ft_putstr("\ntestmax, cote : \n");
  ft_putnbr(cote);
  if (pos->max1 > cote && piece[cote - pos->ini] != '.')
  return (0);
  return (1);
  }*/
//verif si carre parfait strictement plus grand que 4 de cote :i
//WARNING FAIRE LE CAS OU LE CARRE PARFAIT EST PLUS PETIT que 4 DE COTES 

//verif si carre parfait strictement plus grand que 4 de cote :
int		ft_verifdispo(char **carre, t_elem	*piece)
{
	int		i;
	int		hashtag;
	int		j;
	int		a;
	char	*piece1;
	int		y;
	int		x;

	piece1 = (char *)(piece->content);
	j = 0;
	i = 0;
	a = 0;
	y = 0;
	x = 0;
	hashtag = 0;
	ft_putstr("\nwidth : ");
	ft_putnbr(piece->width);
	ft_putstr("\nheight : ");
	ft_putnbr(piece->height);
	ft_putstr("\n");
	while (carre[a] && carre[a][j] && hashtag != 4)
	{
		ft_putstr("\npos :"); //debug
		ft_putnbr(j); //debug
		ft_putstr("\ni :"); //debug
		ft_putnbr(i); //debug
		if (carre[a][j] == '\0')
		{
			a++;
			j = 0;
		}
		else if (carre[a][j] != '.')
			j++;
		else
		{
			while (i < 16 && carre[a + x] && carre[a + x][j + y]
					&& carre[a + x][j + y] == '.')
			{
				if (piece1[i] == '.')
					i++;
				else
				{
					ft_putstr("\nposition ok");
					hashtag++;
					ft_putnbr(hashtag);
					if (i >= 12)
					{
						y = i - 12;
						x = 3;
					}
					else if (i >= 8)
					{
						y = i - 8;
						x = 2;
					}
					else if (i >= 4)
					{
						ft_putstr("je suis la");
						y = i - 4;
						x = 1;
					}
					else
					{
						y = i;
						x = 0;
					}
					i++;
				}
				ft_putstr("\n-------------------------------\n");
				ft_putstr("\nvaleur de j + y : ");
				ft_putnbr(j + y);
				ft_putstr("\nvaleur de a + x : ");
				ft_putnbr(a + x);
				ft_putstr("\nvaleur de i : ");
				ft_putnbr(i);
				ft_putstr("\n");
				ft_putstr("\n-------------------------------\n");
			}
			if (hashtag != 4)
			{
				i = 0;
				hashtag = 0;
			}
		}
	}
	return (hashtag == 4 ? 1 : 0);
}

char	**ft_erase(char lettre, char **carre)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (carre[i])
	{
		while (carre[i][j] == lettre)
			carre[i][j++] = '.';
		i++;
	}
	return (carre);
}

int		ft_placement(t_elem const *piece, char **carre, int cote)
{
	int			x;
	int			y;
	t_elem		*tmp;

	x = 0;
	y = 0;
	tmp = (t_elem *)piece;
	while (carre[x][y] != '\0' && carre[x]  && tmp->content)
	{
		ft_putstr("\n carre a remplir : \n"); //debug
		ft_affres(carre); //debug
		if (carre[x][y] == '\0')
			x++;
		else if (carre[x][y] != '.')
			y++;
		else
		{
			ft_putstr("\n piece a placer :\n"); //debug
			//ft_affres(tmp->content); //debug
			if (ft_verifdispo(carre, tmp))
			{
				//	ft_putstr("\n Emplacement disponible"); //debug
				//	ft_putpiece(carre, tmp->content, &pos);
				ft_putstr("\nnew carre :\n"); //debug
				ft_affres(carre); //debug
				ft_putstr("\n"); //debug
				if (tmp->next == NULL)
				{
					ft_putstr("OUEP"); //debug
					return (1);
				}
				if (ft_placement(tmp->next, carre, cote))
				{
					ft_putstr("\nDONE\n"); //debug
					return (1);
				}
			}
		}
	}
	//carre[pos] = '.';
	ft_putstr("\n\n\n\n\n-------------------------------");//debug
	ft_putstr("\n-------------retour------------\n");//debug
	ft_putstr("-------------------------------\n\n\n\n");//debug
	if(tmp->prev != NULL)
		carre = ft_erase(tmp->prev->lettre, carre);
	return (0);
}

char	**ft_carrevide(int c)
{
	int		i;
	int		j;
	char	**carre;
	char	*col;

	i = 0;
	j = 0;
	carre = (char **)malloc(sizeof(char *) * (c + 1));
	if (carre == NULL)
		return (NULL);
	while (i < c)
	{
		col = (char *)malloc(sizeof(char) * (c + 1));
		if (col == NULL)
		{
			free(carre);
			return (NULL);
		}
		while (j < c)
		{
			col[j++] = '.';
		}
		col[j] = '\0';
		carre[i] = col;
		j = 0;
		i++;
	}
	carre[i] = NULL;
	return (carre);
}

void	ft_affres(char **res)
{
	int		x;

	x = 0;
	while (res[x])
	{
		ft_putstr(res[x]);
		ft_putchar('\n');
		x++;
	}
}

char	*ft_resolution(t_dbllist	*list_piece, int nb_pieces)
{
	int			cote;
	char		**res;

	cote = ft_sqrtfillit(4 * nb_pieces);
	ft_putstr("cote : \n"); //debug
	ft_putnbr(cote); //debug
	ft_putstr(" \n"); //debug
	ft_putstr("list recue : \n"); //debug
	ft_putlsthead(list_piece); //debug
	res = ft_carrevide(cote);
	while (ft_placement(list_piece->head, res, cote) == 0)
	{
		ft_putstr("impossible");
		cote++;
		if (res)
			ft_memdel((void **)res);
		res = ft_carrevide(cote);
	}
	ft_putstr("\nres : \n"); //debug
	ft_affres(res);
	return (*res);
	//	ft_placement(list_piece, car, cote);
}
