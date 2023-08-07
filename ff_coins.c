/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_coins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:20:28 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/07 22:40:00 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	find_coins_ff(t_game *game, char **map)
{
	int		i;
	int		j;
	int		width;
	int		height;
	int		coins;

	i = 1;
	j = 1;
	coins = 0;
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
	return (coins);
}

int	f_fill_coin(t_point *point, int p_y, int p_x, int *c_f)
{
	int		c_x;
	int		c_y;
	int		map_h;
	int		map_w;
	char	**map;

	map = point->mapcheck;
	c_x = p_x;
	c_y = p_y;
	map_w = point->map_w;
	map_h = point->map_h;
	if (c_y < 1 || c_x < 1 || map[c_y][c_x] == '1' || map[c_y][c_x] == 'F'
		|| map[c_y][c_x] == 'S')
		return (0);
	if (c_y >= map_h || c_x >= map_w)
		return (0);
	if (map[c_y][c_x] == 'C')
		(*c_f)++;
	map[c_y][c_x] = 'F';
	if (f_fill_coin(point, c_y + 1, c_x, c_f)
		|| f_fill_coin(point, c_y - 1, c_x, c_f)
		|| f_fill_coin(point, c_y, c_x + 1, c_f)
		|| f_fill_coin(point, c_y, c_x - 1, c_f))
		return (1);
	return (0);
}

void	check_win_coins(t_game *game, t_point *point)
{
	int	p_x;
	int	p_y;
	int	coins_found;
	int	coins_needed;

	p_x = game->p_x;
	p_y = game->p_y;
	coins_found = 0;
	point = ft_calloc(sizeof(t_point), 1);
	cpy_map(game, point);
	coins_needed = find_coins_ff(game, point->mapcheck);
	f_fill_coin(point, p_y, p_x, &coins_found);
	coins_found = 10;
	coins_needed = 10;
	if (coins_found != coins_needed)
		print_error2(game, point, P_CANT_FINISH);
	free_map_to_check(point);
}
