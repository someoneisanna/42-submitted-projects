/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   7_close_window.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/18 10:22:00 by ataboada          #+#    #+#             */
/*   Updated: 2023/06/21 16:37:41 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int		ft_close_win(t_data *data);
void	ft_destroy_display(t_data *data);
void	ft_free_map(char **map);
void	ft_free_sprites(t_data *data);

// close the window and free all allocated memory
int	ft_close_win(t_data *data)
{
	ft_destroy_display(data);
	exit(0);
	return (0);
}

// free all allocated memory (including sprites, map, display and window)
void	ft_destroy_display(t_data *data)
{
	if (data)
		ft_free_sprites(data);
	if (data->map.map)
		ft_free_map(data->map.map);
	if (data->mlx.win)
		mlx_destroy_window(data->mlx.mlx, data->mlx.win);
	if (data->mlx.mlx)
		mlx_destroy_display(data->mlx.mlx);
	free(data->mlx.mlx);
}

// free the map (it is a 2D array of strings, so we
// need to free each str and the array itself)
void	ft_free_map(char **map)
{
	int	i;

	i = 0;
	if (!map)
		return ;
	while (map[i])
	{
		free(map[i]);
		i++;
	}
	free(map);
}

// free all sprites that were used in the game
void	ft_free_sprites(t_data *data)
{
	if (data->spr.f_img)
		mlx_destroy_image(data->mlx.mlx, data->spr.f_img);
	if (data->spr.p_img)
		mlx_destroy_image(data->mlx.mlx, data->spr.p_img);
	if (data->spr.c_img)
		mlx_destroy_image(data->mlx.mlx, data->spr.c_img);
	if (data->spr.e_img)
		mlx_destroy_image(data->mlx.mlx, data->spr.e_img);
	if (data->spr.w_img)
		mlx_destroy_image(data->mlx.mlx, data->spr.w_img);
}
