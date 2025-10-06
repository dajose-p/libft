/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: danjose- <danjose-@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 12:12:52 by danjose-          #+#    #+#             */
/*   Updated: 2025/10/06 12:15:26 by danjose-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

int	ft_lstsize(t_list *lst)
{
	int	i;
	t_list	*head;

	i = 0;
	head = lst;
	while (head)
	{
		head = head->next;
		i++;
	}
	return (i);
}
