/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpingf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 19:30:54 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/11/15 19:20:35 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	minindex(t_list *stack)
{
	t_list	*tmp;
	int		index;
	int		minind;
	int		minval;

	tmp = stack;
	minval = stack->value;
	index = 0;
	minind = 0;
	while (tmp->next)
	{
		index++;
		if (tmp->next->value < minval)
		{
			minind = index;
			minval = tmp->next->value;
		}
		tmp = tmp->next;
	}
	return (minind);
}

void	totop(t_list **stacka)
{
	int	index;
	int	size;

	size = ft_lstsize(*stacka);
	index = minindex(*stacka);
	if (index <= size / 2)
	{
		while (index--)
			ra(stacka);
	}
	else
	{
		while (size - index)
		{
			rra(stacka);
			size--;
		}
	}
}
