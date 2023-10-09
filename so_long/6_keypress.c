/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6_keypress.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 09:55:02 by ataboada          #+#    #+#             */
/*   Updated: 2023/06/22 16:38:16 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_keypress(int keycode, t_data *data);
int	ft_move_player(t_data *d, int x, int y);

// handle keypresses
int	ft_keypress(int keycode, t_data *data)
{
	int	to_print;

	to_print = 0;
	if (keycode == ESC)
		ft_close_win(data);
	else if (keycode == UP)
		to_print = ft_move_player(data, data->plr.p_c, data->plr.p_r - 1);
	else if (keycode == LEFT)
		to_print = ft_move_player(data, data->plr.p_c - 1, data->plr.p_r);
	else if (keycode == DOWN)
		to_print = ft_move_player(data, data->plr.p_c, data->plr.p_r + 1);
	else if (keycode == RIGHT)
		to_print = ft_move_player(data, data->plr.p_c + 1, data->plr.p_r);
	if (to_print == 1)
		ft_printf("Moves: %i\n", data->plr.n_moves);
	return (0);
}

// move the player according to the key that was pressed
int	ft_move_player(t_data *d, int x, int y)
{
	if (d->map.map[y][x] == '0' || d->map.map[y][x] == 'C')
	{
		mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
			d->spr.f_img, d->plr.p_c * SIZE, d->plr.p_r * SIZE);
		mlx_put_image_to_window(d->mlx.mlx, d->mlx.win,
			d->spr.p_img, x * SIZE, y * SIZE);
		if (d->map.map[y][x] == 'C')
			d->plr.to_collect--;
		d->map.map[d->plr.p_r][d->plr.p_c] = '0';
		d->map.map[y][x] = '0';
		d->plr.p_c = x;
		d->plr.p_r = y;
		d->plr.n_moves++;
		return (1);
	}
	if (d->map.map[y][x] == 'E' && d->plr.to_collect == 0)
	{
		ft_printf("Moves: %i\n", d->plr.n_moves + 1);
		ft_printf("Congratulations, you finished the game!\n");
		ft_close_win(d);
	}
	return (0);
}
