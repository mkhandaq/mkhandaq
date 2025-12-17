/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 18:57:48 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/11/14 16:45:14 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	pa(t_list **stacka, t_list **stackb)
{
	int	val;
	int	index;

	if (!*stackb)
		return ;
	index = (*stackb)->index;
	val = pop(stackb);
	push(stacka, val, index);
	write(1, "pa\n", 3);
}

void	pb(t_list **stackb, t_list **stacka)
{
	int	val;
	int	index;

	if (!*stacka)
		return ;
	index = (*stacka)->index;
	val = pop(stacka);
	push(stackb, val, index);
	write(1, "pb\n", 3);
}
