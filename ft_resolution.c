/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_resolution.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mpaincha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/11 11:37:37 by mpaincha          #+#    #+#             */
/*   Updated: 2015/12/21 17:26:22 by kvignau          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
//REGARDER QUAND LA PIECE NES PAS TESTE A PARTIR DE LA POSITION POS 0)
void	ft_putpiece(char *carre, char *piece, t_pos *pos)
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
}

int		ft_newpos(int j, t_pos *pos)
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
}
//verif si carre parfait strictement plus grand que 4 de cote :i
//WARNING FAIRE LE CAS OU LE CARRE PARFAIT EST PLUS PETIT que 4 DE COTES 

//verif si carre parfait strictement plus grand que 4 de cote :
int		ft_verifdispo(char *carre, t_elem	*piece, int cote, t_pos pos)
{
	int		i;
	int		hashtag;
	int		j;
	int		poscote;
	int		a;
	int		z;
	char	*piece1;

	piece1 = (char *)(piece->content);
	j = pos.ini;
	i = 0;
	hashtag = 0;
	a = 0;
	z = -1;
	poscote = cote;
	ft_putstr("\nwidth : ");
	ft_putnbr(piece->width);
	ft_putstr("\nheight : ");
	ft_putnbr(piece->height);
	ft_putstr("\n");
	while (i < 16 && carre[j] && hashtag != 4)
	{
		ft_putstr("\npos :"); //debug
		ft_putnbr(j); //debug
		ft_putstr("\ni :"); //debug
		ft_putnbr(i); //debug
		if (piece1[i] != '.')
		{
			z++;
			/*if (!ft_testmax(cote, &pos, piece->content))
			{
				ft_putstr("CARRE NON OK COUCOU JE SUIS LA HE HO HE HO");
				return (0);
			}*/
			ft_putchar(carre[j]); //debug
			ft_putnbr(j);
			/*if (i % cote == 0 && i > 0)
			{
				poscote = cote * z;
				z++;
			}
			if ((pos.ini - 1) + piece->width > poscote - 1)
			{
				ft_putstr("\nCOUCOU JE SORS");
				ft_putstr("\npos ini : \n");
				ft_putnbr(pos.ini);
				ft_putstr("\n taille piece : ");
				ft_putnbr(piece->width);
				ft_putstr("\n taille carre : ");
				ft_putnbr(poscote);
				ft_putstr("\nje me trouve donc : ");
				ft_putnbr((pos.ini - 1) + piece->width);
				ft_putstr("\n\n\n\n");
				return (0);
			}
			if (pos.ini + (6 * (piece->height) - 1) > (cote * cote) - 1)
				return (0);*/
			/*if (i >= 12)
				a = a + cote - (i - 12);
			else if (i >= 8)
				a = a + cote - (i - 8);
			else if (i >= 4)
				a = a + cote - (i - 4);
			else*/
			if (i < 4)
				a = j + z;
			else
				a = a + cote - z;
			ft_putstr("\n\n\nVALEUR DE I : ");
			ft_putnbr(i);
			ft_putstr("\n\nVALEUR DE A : ");
			ft_putnbr(a);
			ft_putstr("\n\nVALEUR DE Z : ");
			ft_putnbr(z);
			ft_putstr("\n\nVALEUR DE J : ");
			ft_putnbr(j);
			ft_putstr("\n\n\n");
			if (carre[a] == '.' || a % cote != 0)
			{
				//j = ft_newpos(j, &pos);
				hashtag++;
				ft_putnbr(hashtag);
			}
			else
			{
				j++;
				i = 0;
				hashtag = 0;
			}
		}
		if (i > 0 && i % 4)
			z = 0;
		i++;
	}
	return (hashtag == 4 ? 1 : 0);
}

char	*ft_erase(char lettre, char *carre)
{
	int	i;

	i = 0;
	while (carre[i] != '\0')
	{
		if(carre[i] == lettre)
			carre[i] = '.';
		i++;
	}
	return (carre);
}

int		ft_placement(t_elem const *piece, char *carre, int cote)
{

	t_pos		pos;
	t_elem		*tmp;

	tmp = (t_elem *)piece;
	pos.ini = 0;
	ft_putnbr(pos.ini);

	ft_structpos(&pos, cote);
	while (carre[pos.ini] != '\0' && tmp->content)
	{
		ft_putstr("\n carre a remplir : \n"); //debug
		ft_affres(carre, cote); //debug
		if (carre[pos.ini] != '.')
			pos.ini++;
		else
		{
			ft_putstr("\n piece a placer :\n"); //debug
			ft_affres(tmp->content, 4); //debug
			ft_putstr("\n pos ini :"); //debug
			ft_putnbr(pos.ini);
			ft_structpos(&pos, cote);
			if (ft_verifdispo(carre, tmp, cote, pos))
			{
				ft_putstr("\n Emplacement disponible"); //debug
				ft_putpiece(carre, tmp->content, &pos);
				ft_putstr("\nnew carre :\n"); //debug
				ft_putstr(carre); //debug
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
			pos.ini++;
		}
	}
	//carre[pos] = '.';
	ft_putstr("\n\n\n\n\n-------------------------------");
	ft_putstr("retour");
	ft_putstr("-------------------------------\n\n\n\n");
	carre = ft_erase(tmp->prev->lettre, carre);
	return (0);
}

char	*ft_carrevide(int c)
{
	int		i;
	int		lg;
	char	*carre;

	i = 0;
	lg = c * c;
	carre = (char *)malloc(sizeof(char) * lg + 1);
	if (carre == NULL)
		return (NULL);
	while (i != lg)
		carre[i++] = '.';
	carre[i] = '\0';
	return (carre);
}

void	ft_affres(char *res, int cote)
{
	int		i;
	int		y;

	i = 0;
	y = 1;
	while (res[i])
	{
		if (y == cote)
		{
			ft_putchar(res[i++]);
			ft_putchar('\n');
			y = 1;
		}
		else
		{
			ft_putchar(res[i++]);
			y++;
		}
	}
}

char	*ft_resolution(char *res, t_dbllist	*list_piece, int nb_pieces)
{
	int			cote;

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
			free(res);
		res = ft_carrevide(cote);
	}
	ft_putstr("\nres : \n"); //debug
	ft_putstr(res);
	ft_putstr("\nres : \n"); //debug
	ft_affres(res, cote);
	return (res);
	//	ft_placement(list_piece, car, cote);
}
