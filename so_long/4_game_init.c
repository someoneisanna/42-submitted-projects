/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_game_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/16 15:40:52 by ataboada          #+#    #+#             */
/*   Updated: 2023/06/22 16:32:54 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// initialize the game (init mlx and create window)
void	ft_game_init(t_data *data)
{
	data->mlx.mlx = mlx_init();
	if (!data->mlx.mlx)
		ft_perror("Error\nmlx_init() failed", data);
	data->mlx.win = mlx_new_window(data->mlx.mlx,
			SIZE * data->map.n_columns, SIZE * data->map.n_rows, "so_long");
	if (!data->mlx.win)
	{
		mlx_destroy_display(data->mlx.mlx);
		free(data->mlx.mlx);
		ft_perror("Error\nmlx_new_window() failed", data);
	}
}
