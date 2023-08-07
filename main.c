/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 15:22:53 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/07 21:37:07 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	initial_checks(t_game *game)
{
	game->map_w = calculate_map_cols(&game->map[0]);
	game->map_h = calculate_map_rows(game->map);
	if (game->map_h > 19 || game->map_w > 38)
		print_error2(game, NULL, MAP_WIN_PARAMS);
	game->coins = find_coins(game, game->map);
	game->steps = 0;
}

static void	game_init(t_game *game)
{
	game->mlx = mlx_init();
	game->window = mlx_new_window(game->mlx,
			game->map_w * 64,
			game->map_h * 64 + 30,
			"so_long");
	create_img(game);
	render_all(game, game->map);
}

int	main(int argc, char *argv[])
{
	t_game	*game;

	game = ft_calloc(sizeof(t_game), 1);
	game->img = ft_calloc(sizeof(t_img), 1);
	game->point = NULL;
	check_ber(argc, argv, game);
	game->map = read_map(game, argv[1]);
	initial_checks(game);
	check_all(game, game->point);
	game_init(game);
	mlx_hook(game->window, 17, 1L << 17, window_close, game);
	mlx_hook(game->window, 2, 1L << 0, key_hook, game);
	mlx_loop(game->mlx);
	return (0);
}
