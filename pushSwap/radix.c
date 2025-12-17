/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 03:34:51 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/11/15 19:23:48 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	maxbits(int size)
{
	int	bits;

	bits = 0;
	size--;
	while (size > 0)
	{
		size >>= 1;
		bits++;
	}
	return (bits);
}

void	radix(t_list **stacka, t_list **stackb)
{
	int	maxb;
	int	size;
	int	bit;
	int	i;

	bit = 0;
	i = 0;
	size = ft_lstsize(*stacka);
	maxb = maxbits(size);
	while (bit < maxb)
	{
		i = 0;
		while (i < size)
		{
			if ((((*stacka)->index >> bit) & 1) == 0)
				pb(stackb, stacka);
			else
				ra(stacka);
			i++;
		}
		while (*stackb)
			pa(stacka, stackb);
		bit++;
	}
}
