/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:55:31 by chchour           #+#    #+#             */
/*   Updated: 2023/09/05 19:55:32 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "./ft_printf/ft_printf.h"
# include "./minilibx-linux/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

# define PATHWHITE "minixpm/white50p.xpm"
# define PATHBLOCK "minixpm/block50p.xpm"
# define PATHSTICK "minixpm/stick50p.xpm"
# define PATHCOIN "minixpm/coin50p.xpm"
# define PATHEXIT "minixpm/exit50p.xpm"

typedef struct s_da
{
	struct s_path
	{
		int		x;
		int		y;
		int		coinleft;
		int		exitleft;
		int		*exitdata;
		int		*coindata;
		char	*map;
	}		pa;
	void	*mlx;
	void	*window;
	void	*whiteimage;
	void	*blockimage;
	void	*stickimage;
	void	*coinimage;
	void	*exitimage;
	char	*buffer;
	char	*tmp1;
	char	*tmp2;
	char	*map;
	char	*mapfile;
	int		j;
	int		k;
	int		l;
	int		*coindata;
	int		*exitdata;
	int		*playerdata;
	int		*walldata;
	int		fd;
	int		remember;
	int		allsize;
	int		readsize;
	int		modulo;
	int		image_h;
	int		image_w;
	int		x;
	int		y;
	int		xmax;
	int		ymax;
	int		move;
	int		wallmax;
	int		coinmax;
	int		coinleft;
	int		px;
	int		py;
	int		pcoinleft;
	int		e;
	int		cmaxforv;
	int		cforv;
	int		lforv;
	int		iforv;
	int		iforkey;
}			t_da;

void	ft_putexit(t_da *da);
void	ft_putwall(t_da *da);
void	ft_putcoin(t_da *da);
void	ft_allwhite(t_da *da);
int		ft_up(t_da *da);
int		ft_left(t_da *da);
int		ft_down(t_da *da);
int		ft_right(t_da *da);
int		ft_key(int keycode, t_da *da);
int		ft_mouse(int button, int x, int y);
void	ft_make_image(t_da *da);
void	ft_cpytmp2intmp1(t_da *da);
void	ft_cpybufferintmp1(t_da *da);
void	ft_cpytmp1intmp2(t_da *da);
void	ft_cpybufferintmp2(t_da *da);
int		ft_takefullmap(t_da *da);
int		ft_datacollection(t_da *da);
void	ft_makefullmap(t_da *da, int o);
int		ft_exit(t_da *da);
int		ft_verifmap(t_da *da);
int		ft_ww(t_da *da);
int		ft_dd(t_da *da);
int		ft_ss(t_da *da);
int		ft_aa(t_da *da);
void	ft_init(t_da *da);
void	ft_init2(t_da *da);
void	ft_init3(t_da *da);
void	ft_init4(t_da *da);
void	ft_freeall(t_da *da);
int		ft_datahelper1(t_da *da);
int		ft_datahelper2(t_da *da);
void	ft_datahelper3(t_da *da);
int		ft_datahelper4(t_da *da);
void	ft_cpytmp2intmp1(t_da *da);
void	ft_cpybufferintmp1(t_da *da);
void	ft_cpytmp1intmp2(t_da *da);
void	ft_cpybufferintmp2(t_da *da);
int		ft_maphelper1(t_da *da);
void	ft_maphelper2(t_da *da);
int		ft_maphelper3(t_da *da);
int		ft_verifhelper1(t_da *da);
int		ft_verifhelper2(t_da *da);
int		ft_verifhelper3(t_da *da);
int		ft_verifhelper4(t_da *da);
int		ft_pathfinding(t_da *da);
void	ft_verifcoin(t_da *da, int col, int lig);
int		ft_4path(t_da *da, int col, int lig);
int		ft_verifwall(t_da *da, int col, int lig);
int		ft_ber(char *file);
char	*ft_strrchr(const char *s, int c);
void	ft_coinhelper(t_da *da);
int		ft_mainhelper(t_da *da);
void	ft_init4helper(t_da *da);
void	ft_collectionhelper(t_da *da);
int		ft_takemaphelper(t_da *da);
void	ft_free1(t_da *da);
void	ft_free2(t_da *da);
#endif
