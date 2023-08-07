/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keyhook.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/07 17:37:21 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/07 23:35:37 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 13)
		move_player(game, game->p_y - 1, game->p_x);
	else if (keycode == 1)
		move_player(game, game->p_y + 1, game->p_x);
	else if (keycode == 0)
		move_player(game, game->p_y, game->p_x - 1);
	else if (keycode == 2)
		move_player(game, game->p_y, game->p_x + 1);
	else if (keycode == 53)
		exit_game(game);
	render_all(game, game->map);
	return (0);
}
