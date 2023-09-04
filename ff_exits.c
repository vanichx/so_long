/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ff_exits.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:23:26 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/08 00:34:15 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	f_fill_exit(t_point *point, int p_y, int p_x)
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
	if (c_y < 1 || c_x < 1 || c_y >= map_h || c_x >= map_w)
		return (0);
	if (map[c_y][c_x] == '1' || map[c_y][c_x] == 'F' || map[c_y][c_x] == 'S')
		return (0);
	if (map[c_y][c_x] == 'E')
		return (1);
	map[c_y][c_x] = 'F';
	if (f_fill_exit(point, c_y + 1, c_x)
		|| f_fill_exit(point, c_y - 1, c_x)
		|| f_fill_exit(point, c_y, c_x + 1)
		|| f_fill_exit(point, c_y, c_x - 1))
		return (1);
	return (0);
}

void	check_win_exit(t_game *game, t_point *point)
{
	int	p_x;
	int	p_y;
	int	canreachexit;

	p_x = game->p_x;
	p_y = game->p_y;
	point = ft_calloc(sizeof(t_point), 1);
	cpy_map(game, point);
	canreachexit = f_fill_exit(point, p_y, p_x);
	if (!canreachexit)
		print_error2(game, point, BLOCKED_EXIT_ERR);
	free_map_to_check(point);
}
