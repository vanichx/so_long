/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/17 13:50:10 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/07 23:35:11 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include "mlx/mlx.h"
# include "gnl/get_next_line.h"

# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_W 13

# define MEM_ERROR "Memory allocation error.\n"
# define EXIT_ERR "Map has wrong amount of exits\n"
# define READ_ERROR "Given file path is invalid!\n"
# define ARGS_ERROR "Invalid amount of arguments!\n"
# define NOT_RECTANGULAR "Map is not rectangular.\n"
# define NO_WALLS_ERROR "Map is not surrounded by walls!\n"
# define BLOCKED_EXIT_ERR "The exit is blocked by walls!\n"
# define INVALID_INPUT "Invalid inputs check your .ber file!\n"
# define PLAYER_ERR "Map has to many players , should be only one!\n"
# define COIN_ERR "Map has no coins to collect, should be at least one!\n"
# define MAP_INVALID_ERROR "Map file, has some invalid characters!\n"
# define BER_ERROR "Map file, has ivalid extension!\n"
# define P_CANT_FINISH "Player can't collect all coins to exit the game!\n"
# define MAP_WIN_PARAMS "Map is to big for entire screen!\n"

# define GREEN 0x00FF00

typedef struct s_img
{
	int		img_h;
	int		img_w;
	void	*wall;
	void	*bg;
	void	*coin;
	void	*player;
	void	*exit_o;
	void	*exit_c;
	void	*s;
	void	*poe;
	void	*bg_count;
}				t_img;

typedef struct s_point
{
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		map_h;
	int		map_w;
	char	**mapcheck;
}				t_point;

typedef struct s_game
{
	char	**map;
	int		p_x;
	int		p_y;
	int		map_w;
	int		map_h;
	int		steps;
	int		coins;
	void	*window;
	void	*mlx;
	t_img	*img;
	t_point	*point;
}				t_game;

/*check_ber.c*/
void	check_ber(int argc, char **argv, t_game *game);

/*error_free.c*/
void	free_game(t_game *game);
void	free_point(t_point *point);
int		print_error(t_game *game, t_point *point, char *err_msg);
int		print_error2(t_game *game, t_point *point, char *err_msg);

/*exit_game.c*/
int		exit_game(t_game *game);

/*ff_coins.c*/
int		find_coins_ff(t_game *game, char **map);
int		f_fill_coin(t_point *point, int p_y, int p_x, int *c_f);
void	check_win_coins(t_game *game, t_point *point);

/*ff_exits.c*/
int		f_fill_exit(t_point *point, int p_y, int p_x);
void	check_win_exit(t_game *game, t_point *point);

/*ft_itoa.c*/
char	*ft_itoa(int n, char *ptr);

/*keyhook.c*/
int		key_hook(int keycode, t_game *game);

/*map_read.c*/
size_t	calculate_map_rows(char **map_array);
size_t	calculate_map_cols(char **map_array);
size_t	calculate_ber_map_lines(int fd);
char	**read_map(t_game *game, char *map_file);

/*map_checks.c*/

void	check_rectangular(t_game *game, char **map);
void	check_walls(t_game *game, char **map);
void	find_exit(t_game *game, char **map);
void	find_player(t_game *game, char **map);
int		find_coins(t_game *game, char **map);

/*map_checks_2.c*/
void	find_invalid_chars(t_game *game, char **map);
void	check_all(t_game *game, t_point *point);

/*map_checks_utils.c*/
char	**cpy_map(t_game *game, t_point *point);
void	free_map_to_check(t_point *point);
void	find_player_pos(t_game *game, char **map);

/*map_render.c*/
void	render_all(t_game *game, char **map);

/*moves.c*/
void	move_player(t_game *game, int new_p_x, int new_p_y);

/*print_xpm.c*/
void	create_img(t_game *game);
void	print_w(t_game *game, int x, int y);
void	print_b(t_game *game, int x, int y);
void	print_p(t_game *game, int x, int y);
void	print_eo(t_game *game, int x, int y);
void	print_ec(t_game *game, int x, int y);
void	print_c(t_game *game, int x, int y);

/*print_xpm2.c*/
void	print_ec(t_game *game, int x, int y);
void	print_n(t_game *game, int x, int y);
void	print_s(t_game *game, int x, int y);
void	create_img(t_game *game);

/*utils.c*/
int		window_close(t_game *game);
void	free_map(t_game *game);
int		ft_strcmp(const char *s1, const char *s2);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
#endif