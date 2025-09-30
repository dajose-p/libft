/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/30 20:10:15 by danjose-          #+#    #+#             */
/*   Updated: 2025/09/30 20:34:04 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_strlen(dst);
	while (size < j - 1)
		return (ft_strlen(src) + size);
	while (src[i] && ((j + i) < size - 1))
	{
		dst[i + j] = src[i];
		i++;
	}
	dst[i + j] = '\0';
	return (ft_strlen(src) + j);
}
