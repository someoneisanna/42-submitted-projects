/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_map_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 19:39:59 by ataboada          #+#    #+#             */
/*   Updated: 2023/06/22 16:43:57 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_check(t_data *data);
int		ft_check_characters(t_data *data);
int		ft_check_retangular(t_data *data);
int		ft_check_walls(t_data *data);
int		ft_check_path(t_data *data);

// check if the map is valid according to the rules
void	ft_map_check(t_data *data)
{
	if (data->map.n_rows < 3 || data->map.n_columns < 5)
		ft_perror("Error\nInvalid map - map is too small\n", data);
	if (ft_check_characters(data) == 0)
		ft_perror("Error\nInvalid map - wrong number of characters\n", data);
	if (ft_check_retangular(data) == 0)
		ft_perror("Error\nInvalid map - map is not retangular\n", data);
	if (ft_check_walls(data) == 0)
		ft_perror("Error\nInvalid map - map is not surrounded by walls\n", data);
	if (ft_check_path(data) == 0)
		ft_perror("Error\nInvalid map - map has no valid path\n", data);
}

// check if the number of characters is valid and if there are
// only 01CEP characters
int	ft_check_characters(t_data *d)
{
	d->i = 0;
	while (d->i < d->map.n_rows)
	{
		d->j = 0;
		while (d->j < d->map.n_columns)
		{
			if (d->map.map[d->i][d->j] == 'C')
				d->map.n_collectibles++;
			else if (d->map.map[d->i][d->j] == 'E')
				d->map.n_exits++;
			else if (d->map.map[d->i][d->j] == 'P')
			{
				d->map.n_players++;
				d->plr.p_r = d->i;
				d->plr.p_c = d->j;
			}
			else if (ft_strchr("01CEP", d->map.map[d->i][d->j]) == 0)
				ft_perror("Error\nInvalid map - wrong character was found\n", d);
			d->j++;
		}
		d->i++;
	}
	return (d->map.n_collectibles >= 1 && d->map.n_exits == 1
		&& d->map.n_players == 1);
}

// check if the map is retangular (all lines have the same number of columns)
int	ft_check_retangular(t_data *d)
{
	d->i = 0;
	while (d->i < d->map.n_rows)
	{
		if (ft_strlen(d->map.map[d->i]) != d->map.n_columns)
			return (0);
		d->i++;
	}
	return (1);
}

// check if the map is surrounded by walls (all lines start and end with 1)
int	ft_check_walls(t_data *d)
{
	d->i = 0;
	while (d->i < d->map.n_rows)
	{
		if (d->map.map[d->i][0] != '1'
				|| d->map.map[d->i][d->map.n_columns - 1] != '1')
			return (0);
		d->i++;
	}
	d->i = 0;
	while (d->i < d->map.n_columns)
	{
		if (d->map.map[0][d->i] != '1'
				|| d->map.map[d->map.n_rows - 1][d->i] != '1')
			return (0);
		d->i++;
	}
	return (1);
}

// check if the map has a valid path (all 0 are connected to the player)
int	ft_check_path(t_data *d)
{
	int		e;
	char	**map_cpy;

	d->i = 0;
	e = 0;
	map_cpy = ft_calloc(d->map.n_rows + 1, sizeof(char *));
	if (!map_cpy)
		ft_perror("Error\nMalloc failed\n", d);
	while (d->i < d->map.n_rows)
	{
		map_cpy[d->i] = ft_strdup(d->map.map[d->i]);
		{
			if (!d->map.map[d->i])
			{
				ft_free_map(map_cpy);
				ft_perror("Error\nMalloc failed\n", d);
			}
		}
		d->i++;
	}
	e = ft_flood_fill(d, map_cpy, d->plr.p_r, d->plr.p_c);
	ft_free_map(map_cpy);
	return (e);
}
