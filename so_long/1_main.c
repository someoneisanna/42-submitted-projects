/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1_main.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:14:54 by ataboada          #+#    #+#             */
/*   Updated: 2023/07/03 15:23:09 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_args(int argc, char **argv, t_data *data);
void	ft_perror(char *str, t_data *data);
int		ft_flood_fill(t_data *d, char **map, int x, int y);

// call the main functions of the game
int	main(int argc, char **argv)
{
	t_data	data;

	ft_bzero(&data, sizeof(t_data));
	ft_bzero(&data.plr, sizeof(t_plr));
	ft_check_args(argc, argv, &data);
	ft_map_init(&data, argv[1]);
	ft_map_check(&data);
	ft_game_init(&data);
	ft_render_xpm(&data);
	ft_render_map(&data);
	data.plr.to_collect = data.map.n_collectibles;
	mlx_hook(data.mlx.win, 2, 1L << 0, ft_keypress, &data);
	mlx_hook(data.mlx.win, 17, 1L << 17, ft_close_win, &data);
	mlx_loop(data.mlx.mlx);
}

// check if the arguments are correct
void	ft_check_args(int argc, char **argv, t_data *data)
{
	int	i;

	i = 0;
	if (argc != 2)
		ft_perror("Error\nUsage: ./so_long [map.ber]\n", data);
	while (argv[1][i])
		i++;
	if (argv[1][i - 1] != 'r' || argv[1][i - 2] != 'e' || argv[1][i - 3] != 'b'
			|| argv[1][i - 4] != '.')
		ft_perror("Error\nUsage: ./so_long [map.ber]\n", data);
}

// print error message and free everything that was used
void	ft_perror(char *str, t_data *data)
{
	ft_printf("%s", str);
	ft_close_win(data);
	exit(0);
}

// recursive function to check if the map is valid
int	ft_flood_fill(t_data *d, char **map, int x, int y)
{
	int			n_collectibles;
	static int	c;
	static int	e;

	n_collectibles = d->map.n_collectibles;
	if (map[y][x] == '1')
		return (0);
	else if (map[y][x] == 'C')
		c += 1;
	else if (map[y][x] == 'E')
	{
		e = 1;
		return (0);
	}
	map[y][x] = '1';
	ft_flood_fill(d, map, x + 1, y);
	ft_flood_fill(d, map, x - 1, y);
	ft_flood_fill(d, map, x, y + 1);
	ft_flood_fill(d, map, x, y - 1);
	if (c == n_collectibles && e == 1)
		return (1);
	else
		return (0);
}
