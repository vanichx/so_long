/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/21 12:57:43 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/07 23:34:33 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

int	window_close(t_game *game)
{
	exit_game(game);
	return (0);
}

void	free_map(t_game *game)
{
	int	i;
	int	map_h;

	map_h = game->map_h;
	i = 0;
	while (i < map_h)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++; 
	}
	if (s1[i] == '\0' && s2[i] != '\0')
		return (0 - s2[i]);
	if (s1[i] != '\0' && s2[i] == '\0')
		return (s1[i]);
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*str;

	str = s;
	while (n > 0)
	{
		*str++ = 0;
		n--;
	}
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	bytes;
	void	*ptr;

	bytes = nmemb * size;
	if (size && (bytes / size) != nmemb)
		return (NULL);
	ptr = malloc(bytes);
	if (NULL == ptr)
		return (NULL);
	ft_bzero(ptr, bytes);
	return (ptr);
}
