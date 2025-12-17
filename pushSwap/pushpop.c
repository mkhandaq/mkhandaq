/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushpop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:25:43 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/11/14 16:41:44 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"
#include <stdio.h>

void	push(t_list **stack, int value, int index)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return ;
	new->value = value;
	new->index = index;
	new->next = *stack;
	*stack = new;
}

int	pop(t_list **stack)
{
	t_list	*head;
	int		val;

	if (!*stack)
		return (-1);
	head = *stack;
	val = head->value;
	*stack = head->next;
	free(head);
	return (val);
}
