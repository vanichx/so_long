/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 16:01:19 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/07 22:31:16 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	free_game(t_game *game)
{
	int	i;

	i = 0;
	if (game->img)
		free(game->img);
	if (game)
	{
		if (game->map)
			free_map(game);
		free(game);
	}
	exit(0);
}

void	free_point(t_point *point)
{
	int	i;

	i = 0;
	if (point)
	{
		if (point->mapcheck)
		{
			while (i < point->map_h)
			{
				free(point->mapcheck[i]);
				i++;
			}
			free(point->mapcheck);
		}
		free(point);
	}
	exit(0);
}

int	print_error2(t_game *game, t_point *point, char *err_msg)
{
	write(2, "Error\n", 7);
	if (err_msg && ft_strcmp(err_msg, MAP_INVALID_ERROR) == 0)
		write(2, MAP_INVALID_ERROR, 40);
	else if (err_msg && ft_strcmp(err_msg, BLOCKED_EXIT_ERR) == 0)
		write(2, BLOCKED_EXIT_ERR, 31);
	else if (err_msg && ft_strcmp(err_msg, P_CANT_FINISH) == 0)
		write(2, P_CANT_FINISH, 50);
	else if (err_msg && ft_strcmp(err_msg, BER_ERROR) == 0)
		write(2, BER_ERROR, 33);
	else if (err_msg && ft_strcmp(err_msg, MAP_WIN_PARAMS) == 0)
		write(2, MAP_WIN_PARAMS, 34);
	if (game)
		free_game(game);
	if (point)
		free_point(point);
	exit(0);
	return (0);
}

int	print_error(t_game *game, t_point *point, char *err_msg)
{
	write(2, "Error\n", 7);
	if (err_msg && ft_strcmp(err_msg, ARGS_ERROR) == 0)
		write(2, ARGS_ERROR, 30);
	else if (err_msg && ft_strcmp(err_msg, READ_ERROR) == 0)
		write(2, READ_ERROR, 29);
	else if (err_msg && ft_strcmp(err_msg, INVALID_INPUT) == 0)
		write(2, INVALID_INPUT, 38);
	else if (err_msg && ft_strcmp(err_msg, NOT_RECTANGULAR) == 0)
		write(2, NOT_RECTANGULAR, 25);
	else if (err_msg && ft_strcmp(err_msg, NO_WALLS_ERROR) == 0)
		write(2, NO_WALLS_ERROR, 33);
	else if (err_msg && ft_strcmp(err_msg, EXIT_ERR) == 0)
		write(2, EXIT_ERR, 31);
	else if (err_msg && ft_strcmp(err_msg, PLAYER_ERR) == 0)
		write(2, PLAYER_ERR, 47);
	else if (err_msg && ft_strcmp(err_msg, COIN_ERR) == 0)
		write(2, COIN_ERR, 54);
	if (game)
		free_game(game);
	if (point)
		free_point(point);
	exit(0);
	return (0);
}
