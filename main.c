/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chchour <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 19:54:46 by chchour           #+#    #+#             */
/*   Updated: 2023/09/05 19:54:48 by chchour          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_ber(char *file)
{
	int	i;

	i = 0;
	while (file[i] != '\0')
		i++;
	if (i < 5)
		return (1);
	if (file[i - 4] != '.')
		return (1);
	if (file[i - 3] != 'b')
		return (1);
	if (file[i - 2] != 'e')
		return (1);
	if (file[i - 1] != 'r')
		return (1);
	return (0);
}

int	ft_exit(t_da *da)
{
	ft_freeall(da);
	exit(0);
}

int	ft_key(int keycode, t_da *da)
{
	if (keycode == 65307)
		ft_exit(da);
	else if (keycode == 119 || keycode == 65362)
		ft_up(da);
	else if (keycode == 97 || keycode == 65361)
		ft_left(da);
	else if (keycode == 115 || keycode == 65364)
		ft_down(da);
	else if (keycode == 100 || keycode == 65363)
		ft_right(da);
	if (da->coinleft != 0)
	{
		ft_coinhelper(da);
	}
	if (da->x != da->exitdata[0] || da->y != da->exitdata[1])
		mlx_put_image_to_window(da->mlx, da->window, da->exitimage,
			da->exitdata[0], da->exitdata[1]);
	return (1);
}

int	ft_mouse(int button, int x, int y)
{
	ft_printf("button = %d\nx = %d\ny = %d\n", button, x, y);
	return (0);
}

int	main(int argc, char **argv)
{
	t_da	da;

	if (argc != 2)
	{
		ft_printf("Error\nwrong argument number\n");
		return (0);
	}
	if (argv[1] == NULL)
	{
		ft_printf("Error\nwrong argument\n");
		return (0);
	}
	if (ft_ber(argv[1]) == 1)
	{
		ft_printf("Error\nonly .ber ber is love, ber is life\n");
		return (0);
	}
	da.mapfile = argv[1];
	if (ft_mainhelper(&da) == 1)
		return (0);
	mlx_hook(da.window, 2, 1L << 0, ft_key, &da);
	mlx_hook(da.window, 4, 1L << 2, ft_mouse, NULL);
	mlx_hook(da.window, 17, 0, ft_exit, &da);
	mlx_loop(da.mlx);
	return (0);
}
