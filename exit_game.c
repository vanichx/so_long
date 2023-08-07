/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/03 15:51:57 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/07 23:35:42 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	exit_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->bg);
	mlx_destroy_image(game->mlx, game->img->wall);
	mlx_destroy_image(game->mlx, game->img->coin);
	mlx_destroy_image(game->mlx, game->img->player);
	mlx_destroy_image(game->mlx, game->img->exit_c);
	mlx_destroy_image(game->mlx, game->img->exit_o);
	mlx_destroy_image(game->mlx, game->img->bg_count);
	mlx_destroy_image(game->mlx, game->img->poe);
	mlx_destroy_image(game->mlx, game->img->s);
	mlx_destroy_window(game->mlx, game->window);
	if (game)
		free_game(game);
	if (game->point)
		free_point(game->point);
	exit(0);
}
