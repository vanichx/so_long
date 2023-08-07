/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:51:51 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/07 21:35:06 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

size_t	calculate_map_rows(char **map_array)
{
	size_t	rows;

	rows = 0;
	if (map_array == NULL)
		return (0);
	while (map_array[rows] != NULL)
		rows++;
	return (rows);
}

size_t	calculate_map_cols(char **map_array)
{
	size_t	columns;

	if (map_array == NULL || map_array[0] == NULL)
		return (0);
	columns = 0;
	while (map_array[0][columns] == '1')
		columns++;
	return (columns);
}

size_t	calculate_ber_map_lines(int fd)
{
	size_t	i;
	char	*line;

	i = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		i++;
	}
	return (i);
}

char	**read_map(t_game *game, char *map_file)
{
	int		i;
	int		fd;
	char	*line;
	char	**map;

	fd = open(map_file, O_RDONLY);
	if (fd == -1)
		print_error(game, NULL, READ_ERROR);
	map = ft_calloc(sizeof(char *), calculate_ber_map_lines(fd) + 1);
	if (!map)
		return (0);
	close(fd);
	fd = open(map_file, O_RDONLY);
	line = get_next_line(fd);
	i = 0;
	while (line)
	{
		map[i] = line;
		line = get_next_line(fd);
		i++;
	}
	map[i] = 0;
	close(fd);
	return (map);
}
