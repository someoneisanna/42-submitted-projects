/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_map_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ataboada <ataboada@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 12:01:07 by ataboada          #+#    #+#             */
/*   Updated: 2023/06/21 16:32:27 by ataboada         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_init(t_data *data, char *path);
int		ft_count_columns(int fd);
int		ft_count_rows(int fd);
char	**ft_create_map_array(t_data *data, char *path);

// initialize the map struct
// the number of characters will be updated in the map_check function
void	ft_map_init(t_data *data, char *path)
{
	data->map.fd = open(path, O_RDONLY);
	if (data->map.fd == -1)
		ft_perror("Error\nMap file not found\n", data);
	data->map.n_columns = ft_count_columns(data->map.fd);
	data->map.n_rows = ft_count_rows(data->map.fd);
	data->map.map = ft_create_map_array(data, path);
	data->map.n_collectibles = 0;
	data->map.n_exits = 0;
	data->map.n_players = 0;
	close (data->map.fd);
}

// count the number of columns in the map (as it should be
// a rectangle, we just count the length of the first line)
int	ft_count_columns(int fd)
{
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			break ;
		i++;
	}
	return (i);
}

// count the number of lines in the map (we add 1 to count
// the last line)
int	ft_count_rows(int fd)
{
	char	c;
	int		i;

	i = 0;
	while (read(fd, &c, 1))
	{
		if (c == '\n')
			i++;
	}
	return (i + 1);
}

// create a matrix of the map (an array of the lines)
char	**ft_create_map_array(t_data *data, char *path)
{
	int				fd;
	char			*line;
	char			**map;

	data->i = 0;
	fd = open(path, O_RDONLY);
	if (fd == -1)
		ft_perror("Error\nMap file not found\n", data);
	map = (char **)malloc(sizeof(char *) * (data->map.n_rows + 1));
	if (!map)
		ft_perror("Error\nMalloc failed\n", data);
	while (data->i < data->map.n_rows)
	{
		line = get_next_line(fd);
		if (!line)
			ft_perror("Error\nMalloc failed\n", data);
		map[data->i] = malloc(sizeof(char) * (ft_strlen(line) + 1));
		if (!map[data->i])
			ft_perror("Error\nMalloc failed\n", data);
		ft_strlcpy(map[data->i], line, ft_strlen(line));
		free(line);
		data->i++;
	}
	close (fd);
	return (map);
}
