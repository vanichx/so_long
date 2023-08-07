/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 12:35:30 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/07 20:31:05 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_rectangular(t_game *game, char **map)
{
	int	i;
	int	rows;
	int	cols;
	int	curr_row_lenght;

	if (!game || !map)
		print_error(game, NULL, INVALID_INPUT);
	i = 0;
	cols = game->map_w;
	rows = game->map_h;
	while (i < rows)
	{
		curr_row_lenght = ft_strlen(map[i]);
		if (curr_row_lenght != cols)
			print_error(game, NULL, NOT_RECTANGULAR);
		i++;
	}
}

void	check_walls(t_game *game, char **map)
{
	int		i;
	int		j;
	int		width;
	int		height;

	i = 0;
	j = 0;
	height = game->map_h;
	width = game->map_w;
	while (i < height)
	{
		if (map[i][0] != '1' || map[i][width - 1] != '1')
			print_error(game, NULL, NO_WALLS_ERROR);
		i++;
	}
	j = 0;
	while (j < width - 1)
	{
		if (map[0][j] != '1' || map[height - 1][j] != '1')
			print_error(game, NULL, NO_WALLS_ERROR);
		j++;
	}
}

void	find_exit(t_game *game, char **map)
{
	int		i;
	int		j;
	int		count;
	int		width;
	int		height;

	count = 0;
	i = 1;
	j = 1;
	height = game->map_h;
	width = game->map_w;
	while (i < height - 1)
	{
		j = 1;
		while (j < width - 1)
		{
			if (map[i][j] == 'E')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		print_error(game, NULL, EXIT_ERR);
}

void	find_player(t_game *game, char **map)
{
	int		i;
	int		j;
	int		count;
	int		width;
	int		height;

	count = 0;
	i = 1;
	j = 1;
	height = game->map_h;
	width = game->map_w;
	while (i < height - 1)
	{
		j = 1;
		while (j < width - 1)
		{
			if (map[i][j] == 'P')
				count++;
			j++;
		}
		i++;
	}
	if (count != 1)
		print_error(game, NULL, PLAYER_ERR);
}

int	find_coins(t_game *game, char **map)
{
	int		i;
	int		j;
	int		coins;
	int		width;
	int		height;

	coins = 0;
	i = 1;
	j = 1;
	height = game->map_h;
	width = game->map_w;
	while (i < height - 1)
	{
		j = 1;
		while (j < width - 1)
		{
			if (map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	if (coins < 1)
		print_error(game, NULL, COIN_ERR);
	return (coins);
}
