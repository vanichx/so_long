/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xpm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 16:55:35 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/04 15:17:41 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	print_w(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img->wall, x, y);
}

void	print_b(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img->bg, x, y);
}

void	print_c(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img->coin, x, y);
}

void	print_p(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img->player, x, y);
}

void	print_eo(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img->exit_o, x, y);
}
