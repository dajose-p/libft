/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/01 19:16:49 by danjose-          #+#    #+#             */
/*   Updated: 2025/10/01 19:31:10 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (*s1 && (i < n))
	{
		if (*s1 == *s2)
		{
			s1++;
			s2++;
			n--;
			return (ft_strncmp(s1, s2, n));
		}
		if (*s1 < *s2)
			return (-1);
		if (*s1 > *s2)
			return (1);
		i++;
	}
	return (0);
}
