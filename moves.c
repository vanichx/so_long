/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 19:51:33 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/07 23:36:01 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static void	usual_move(t_game *game, int new_p_y, int new_p_x)
{
	game->map[game->p_y][game->p_x] = '0';
	game->p_x = new_p_x;
	game->p_y = new_p_y;
	game->map[game->p_y][game->p_x] = 'P';
	game->steps++;
}

static void	player_on_exit(t_game *game, int new_p_y, int new_p_x)
{
	game->map[game->p_y][game->p_x] = '0';
	game->p_x = new_p_x;
	game->p_y = new_p_y;
	game->map[game->p_y][game->p_x] = 'N';
	game->steps++;
}

static void	win_game(t_game *game)
{
	write(1, "Congratulations , you win the game!\n", 37);
	exit_game(game);
}

static void	lost_game(t_game *game)
{
	write(1, "Sorry , you lost the game!\nTry one more time <3\n", 49);
	exit_game(game);
}

void	move_player(t_game *game, int new_p_y, int new_p_x)
{
	if (game->map[new_p_y][new_p_x] != '1' && game->map[new_p_y][new_p_x] != 'E'
		&& game->map[new_p_y][new_p_x] != 'S')
	{
		if (game->map[new_p_y][new_p_x] == 'C')
			game->coins--;
		if (game->map[game->p_y][game->p_x] == 'N' 
			&& (game->map[new_p_y][new_p_x] == '0' 
			|| game->map[new_p_y][new_p_x] == 'C'))
		{
			game->map[game->p_y][game->p_x] = 'E';
			game->p_x = new_p_x;
			game->p_y = new_p_y;
			game->map[game->p_y][game->p_x] = 'P';
		}
		usual_move(game, new_p_y, new_p_x);
		render_all(game, game->map);
	}
	else if (game->map[new_p_y][new_p_x] == 'E' && game->coins > 0)
		player_on_exit(game, new_p_y, new_p_x);
	else if (game->map[new_p_y][new_p_x] == 'E' && game->coins == 0)
		win_game(game);
	else if (game->map[new_p_y][new_p_x] == 'S')
		lost_game(game);
}
