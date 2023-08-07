/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_render.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 15:41:32 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/07 23:12:12 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	print_results(t_game *game, int height, int width)
{
	int		bottom;
	int		mid;
	char	info_steps[10];
	char	info_coin[10];

	ft_bzero(info_steps, 10);
	ft_bzero(info_coin, 10);
	ft_itoa(game->steps, info_steps);
	ft_itoa(game->coins, info_coin);
	height = game->map_h;
	width = game->map_w;
	mid = (width * 64 - ((width * 64) / 2));
	bottom = (height * 64 + 15);
	mlx_put_image_to_window(game->mlx, game->window,
		game->img->bg_count, mid - 150, bottom - 15);
	mlx_string_put(game->mlx, game->window,
		mid + 50, bottom, GREEN, "Steps :");
	mlx_string_put(game->mlx, game->window,
		mid + 100, bottom, GREEN, info_steps);
	mlx_string_put(game->mlx, game->window,
		mid - 150, bottom, GREEN, "Coins to collect :");
	mlx_string_put(game->mlx, game->window,
		mid - 15, bottom, GREEN, info_coin);
}

static void	print_exit(t_game *game, int j, int i)
{
	if (game->coins == 0)
		print_eo(game, j * 64, i * 64);
	else
		print_ec(game, j * 64, i * 64);
}

static void	print_all(t_game *game, char **map, int j, int i)
{
	if (map[i][j] == '1')
		print_w(game, j * 64, i * 64);
	else if (map[i][j] == '0')
		print_b(game, j * 64, i * 64);
	else if (map[i][j] == 'C')
		print_c(game, j * 64, i * 64);
	else if (map[i][j] == 'E')
		print_exit(game, j, i);
	else if (map[i][j] == 'P')
		print_p(game, j * 64, i * 64);
	else if (map[i][j] == 'S')
		print_s(game, j * 64, i * 64);
	else if (map[i][j] == 'N')
		print_n(game, j * 64, i * 64);
}

void	render_all(t_game *game, char **map)
{
	int		i;
	int		j;

	i = 0;
	while (i < game->map_h)
	{
		j = 0;
		while (j < game->map_w)
		{
			print_all(game, map, j, i);
			print_results(game, game->map_h, game->map_w);
			j++;
		}
		i++;
	}
}
