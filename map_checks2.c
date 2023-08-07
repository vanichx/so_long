/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 14:08:22 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/07 22:23:33 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	find_invalid_chars(t_game *game, char **map)
{
	int		i;
	int		j;
	int		width;
	int		height;

	i = 1;
	j = 1;
	height = game->map_h;
	width = game->map_w;
	while (i < height - 1)
	{
		j = 1;
		while (j < width - 1)
		{
			if (map[i][j] != '0' && map[i][j] != '1'
			&& map[i][j] != 'C' && map[i][j] != 'E' && map[i][j] != 'P'
			&& map[i][j] != 'S')
				print_error2(game, NULL, MAP_INVALID_ERROR);
			j++;
		}
		i++;
	}
}

void	check_all(t_game *game, t_point *point)
{
	check_rectangular(game, game->map);
	check_walls(game, game->map);
	find_exit(game, game->map);
	find_player(game, game->map);
	find_coins(game, game->map);
	find_invalid_chars(game, game->map);
	find_player_pos(game, game->map);
	check_win_exit(game, point); 
	check_win_coins(game, point);
}
