/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 11:16:17 by ataboada          #+#    #+#             */
/*   Updated: 2023/07/03 15:22:48 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "minilibx-linux/mlx.h"

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define SIZE		50

# define ESC		65307
# define UP			65362
# define DOWN		65364
# define LEFT		65361
# define RIGHT		65363

# define PATH_W		"textures/wall.xpm"
# define PATH_P		"textures/player.xpm"
# define PATH_C		"textures/collectible.xpm"
# define PATH_E		"textures/exit.xpm"
# define PATH_F		"textures/floor.xpm"

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
}				t_mlx;

typedef struct s_map
{
	int				fd;
	char			**map;
	unsigned int	n_columns;
	unsigned int	n_rows;
	unsigned int	n_collectibles;
	unsigned int	n_exits;
	unsigned int	n_players;
}				t_map;

typedef struct s_player
{
	int		p_c;
	int		p_r;
	int		n_moves;
	int		to_collect;
}				t_plr;

typedef struct s_spr
{
	void	*w_img;
	void	*p_img;
	void	*c_img;
	void	*e_img;
	void	*f_img;
	int		width;
	int		height;
}				t_spr;

typedef struct s_data
{
	t_mlx			mlx;
	t_map			map;
	t_spr			spr;
	t_plr			plr;
	unsigned int	i;
	unsigned int	j;
}				t_data;

// 1_main.c
void	ft_check_args(int argc, char **argv, t_data *data);
void	ft_perror(char *str, t_data *data);
int		ft_flood_fill(t_data *d, char **map, int x, int y);

// 2_map_init.c
void	ft_map_init(t_data *data, char *path);
int		ft_count_columns(int fd);
int		ft_count_rows(int fd);
char	**ft_create_map_array(t_data *data, char *path);

// 3_map_check.c
void	ft_map_check(t_data *data);
int		ft_check_characters(t_data *data);
int		ft_check_retangular(t_data *data);
int		ft_check_walls(t_data *data);
int		ft_check_path(t_data *data);

// 4_game_init.c
void	ft_game_init(t_data *data);

// 5_renderings.c
void	ft_render_xpm(t_data *d);
void	ft_render_map(t_data *d);

// 6_keypress.c
int		ft_keypress(int keycode, t_data *data);
int		ft_move_player(t_data *d, int x, int y);

// 7_close_window.c
int		ft_close_win(t_data *data);
void	ft_destroy_display(t_data *data);
void	ft_free_map(char **map);
void	ft_free_sprites(t_data *data);

#endif
