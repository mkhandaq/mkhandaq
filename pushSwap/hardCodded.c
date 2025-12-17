/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hardCodded.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 19:15:46 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/11/15 19:39:51 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	sort2(t_list **stacka)
{
	if (((*stacka)->value) > (((*stacka)->next)->value))
		sa(stacka);
}

static void	sort3(t_list **stacka)
{
	int	a;
	int	b;
	int	c;

	a = (*stacka)->value;
	b = (*stacka)->next->value;
	c = (*stacka)->next->next->value;
	if (b > a && b > c && a < c)
	{
		rra(stacka);
		sa(stacka);
	}
	else if (b < a && b < c && a > c)
		ra(stacka);
	else if (b < a && b > c)
	{
		sa(stacka);
		rra(stacka);
	}
	else if (b < a && b < c && a < c)
		sa(stacka);
	else if (b > a && b > c && a > c)
		rra(stacka);
}

static void	sort4(t_list **stacka, t_list **stackb)
{
	totop(stacka);
	pb(stackb, stacka);
	sort3(stacka);
	pa(stacka, stackb);
}

static void	sort5(t_list **stacka, t_list **stackb)
{
	totop(stacka);
	pb(stackb, stacka);
	sort4(stacka, stackb);
	pa(stacka, stackb);
}

void	handler(t_list **stacka, t_list **stackb, int size)
{
	if (size == 1)
		return ;
	if (issort(stacka))
		return ;
	else if (size == 2)
		sort2(stacka);
	else if (size == 3)
		sort3(stacka);
	else if (size == 4)
		sort4(stacka, stackb);
	else if (size == 5)
		sort5(stacka, stackb);
	else if (size > 5)
		radix(stacka, stackb);
}
