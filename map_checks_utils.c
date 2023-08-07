/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_checks_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 19:59:41 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/07 22:38:59 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

char	**cpy_map(t_game *game, t_point *point)
{
	int	i;
	int	j;

	point->map_h = game->map_h;
	point->map_w = game->map_w;
	point->mapcheck = (char **)malloc(point->map_h * sizeof(char *));
	if (point->mapcheck == NULL)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < point->map_h)
	{
		j = 0;
		point->mapcheck[i] = (char *)malloc((point->map_w + 1) * sizeof(char));
		if (point->mapcheck[i] == NULL)
			exit(EXIT_FAILURE);
		while (j < point->map_w)
		{
			point->mapcheck[i][j] = game->map[i][j];
			j++;
		}
		point->mapcheck[i][point->map_w] = '\0';
		i++;
	}
	return (point->mapcheck);
}

void	free_map_to_check(t_point *point)
{
	int	i;
	int	map_h;

	map_h = point->map_h;
	i = 0;
	while (i < map_h)
	{
		free(point->mapcheck[i]);
		i++;
	}
	free(point->mapcheck);
}

void	find_player_pos(t_game *game, char **map)
{
	int	i;
	int	j;
	int	width;
	int	height;

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
			{
				game->p_x = j;
				game->p_y = i;
			}
			j++;
		}
		i++;
	}
}
