/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_ber.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 14:13:32 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/07 22:10:14 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

void	check_ber(int argc, char **argv, t_game *game)
{
	int		avl;
	int		berl;
	char	*ber;

	ber = ".ber";
	avl = ft_strlen(argv[1]);
	berl = ft_strlen(ber);
	if (argc != 2)
		print_error(game, NULL, ARGS_ERROR);
	if (avl < 6)
		print_error2(game, NULL, BER_ERROR);
	while (berl >= 0)
	{
		if (argv[1][avl] != ber[berl])
			print_error2(game, NULL, BER_ERROR);
		avl--;
		berl--;
	}
}
