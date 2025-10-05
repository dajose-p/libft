/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/05 18:12:27 by danjose-          #+#    #+#             */
/*   Updated: 2025/10/05 20:14:34 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	num_len(int n)
{
	int	i;

	i = 0;
	while (n / 10 > 0)
	{
		i++;
		n /= 10;
	}
	i++;
	return (i);
}

char	*do_itoa(char *res, int len, int n, int i)
{
	int	aux_l;

	aux_l = len;
	while (i < len)
	{
		res[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	res[aux_l] = '\0';
	return (res);
}

char	*min_case(char *res, int n)
{
	if (n == -2147483648)
	{
		res = ft_calloc(12, sizeof(char));
		if (!res)
			return (NULL);
		res[0] = '-';
		res[1] = '2';
		res[2] = '1';
		res[3] = '4';
		res[4] = '7';
		res[5] = '4';
		res[6] = '8';
		res[7] = '3';
		res[8] = '6';
		res[9] = '4';
		res[10] = '8';
		res[11] = '\0';
		return (res);
	}
	return (NULL);
}

char	*ft_itoa(int n)
{
	char	*res;
	int		len;
	int		i;

	len = num_len(n);
	i = 0;
	res = NULL;
	res = min_case(res, n);
	if (res)
		return (res);
	if (n < 0)
	{
		n = -n;
		len = num_len(n) + 1;
		i++;
	}
	res = ft_calloc(len + 1, sizeof(char));
	if (!res)
		return (NULL);
	if (i > 0)
		res[0] = '-';
	res = do_itoa(res, len, n, i);
	return (res);
}
