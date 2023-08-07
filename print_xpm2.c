/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_xpm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 15:17:26 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/07 20:29:02 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	print_ec(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img->exit_c, x, y);
}

void	print_s(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img->s, x, y);
}

void	print_n(t_game *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->window, game->img->poe, x, y);
}

void	create_img(t_game *game)
{
	game->img->bg = mlx_xpm_file_to_image(game->mlx, \
		"./img/0.xpm", &game->img->img_w, &game->img->img_h);
	game->img->wall = mlx_xpm_file_to_image(game->mlx, \
		"./img/1.xpm", &game->img->img_w, &game->img->img_h);
	game->img->coin = mlx_xpm_file_to_image(game->mlx, \
		"./img/C.xpm", &game->img->img_w, &game->img->img_h);
	game->img->exit_c = mlx_xpm_file_to_image(game->mlx, \
		"./img/EC.xpm", &game->img->img_w, &game->img->img_h);
	game->img->exit_o = mlx_xpm_file_to_image(game->mlx, \
		"./img/EO.xpm", &game->img->img_w, &game->img->img_h);
	game->img->player = mlx_xpm_file_to_image(game->mlx, \
		"./img/P.xpm", &game->img->img_w, &game->img->img_h);
	game->img->s = mlx_xpm_file_to_image(game->mlx, \
		"./img/S.xpm", &game->img->img_w, &game->img->img_h);
	game->img->poe = mlx_xpm_file_to_image(game->mlx, \
	"./img/POE.xpm", &game->img->img_w, &game->img->img_h);
	game->img->bg_count = mlx_xpm_file_to_image(game->mlx, \
		"./img/30PX.xpm", &game->img->img_w, &game->img->img_h);
}
