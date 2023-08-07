/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ipetruni <ipetruni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 19:35:40 by ipetruni          #+#    #+#             */
/*   Updated: 2023/08/07 21:09:16 by ipetruni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "solong.h"

static int	ft_len(int n)
{
	size_t	index;

	index = 0;
	if (n <= 0)
		index++;
	while (n)
	{
		index++;
		n = n / 10;
	}
	return (index);
}

char	*ft_itoa(int n, char *ptr)
{
	int		len;

	len = ft_len(n);
	if (!ptr)
		return (NULL);
	ptr[len] = '\0';
	if (n == 0)
		ptr[0] = '0';
	else if (n < 0)
		ptr[0] = '-';
	while (n)
	{
		if (n < 0)
			ptr[--len] = (~(n % 10) + 1) + 48;
		else
			ptr[--len] = (n % 10) + 48;
		n /= 10;
	}
	return (ptr);
}
