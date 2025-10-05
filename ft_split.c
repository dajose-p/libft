/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/04 22:10:49 by danjose-          #+#    #+#             */
/*   Updated: 2025/10/05 02:11:05 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**free_mem(char **split, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(split[i]);
		i++;
	}
	return (split);
}

int     count_words(char const *s, char c)
{
        int     i;
        int     count;

        i = 0;
        count = 0;
        while (s[i])
        {
                if (s[i] != c && ((i == 0) || s[i - 1] == c))
                        count++;
                i++;
        }
        return (count);
}

char	**inner_malloc(char const *s, char c, char **split)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && ((i == 0) || (s[i - 1] == c)))
		{
			split[count - 1] = ft_calloc(j, sizeof(char));
			if (!split)
				return(free_mem(split, count - 1));
			count++;
			j = 0;
		}
		i++;
		j++;
	}
	split[count - 1] = ft_calloc(j, sizeof(char));
	if (!split)
		return(free_mem(split, count));
	return (split);
}

char	**do_split(char const *s, char c, char **split)
{
	int	i;
	int	j;
	int	count;
	int	k;

	i = 0;
	j = 0;
	k = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c && ((i == 0) || (s[i - 1] == c)))
		{
			count++;
			j = 0;
		}
		if (!(s[i + 1] != c && ((i + 1 == 0) || (s[i] == c))))
			split[count - 1][j] = s[i];
		else
			split[count - 1][j] = '\0';
		i++;
		j++;
	}
	return (split);
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int	i;
	int	j;

	i = 0;
	j = 0;
	split = ft_calloc(count_words(s, c) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	split = inner_malloc(s, c, split);
	if (!split)
		return (NULL);
	split = do_split(s, c, split);
	split[count_words(s, c)] = NULL;
	return (split);
}

/*
#include <stdio.h>

int	main(int argc, char **argv)
{
	int i = 0;
	char	**split;

	split = malloc(4 * sizeof(char *));
	while (i < 4)
	{
		split[i] = malloc(5);
		i++;
	}
	i = 0;
	split = ft_split(argv[1], *argv[2]);
	while (split[i] != NULL)
	{
		printf("Word [%i]: %s\n", i, split[i]);
		i++;
	}
}*/
