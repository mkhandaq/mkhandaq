/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 19:05:59 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/11/10 20:35:28 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	rra(t_list **stack)
{
	t_list	*node;
	t_list	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	node = tmp->next;
	tmp->next = NULL;
	node->next = *stack;
	*stack = node;
	write(1, "rra\n", 4);
}

void	rrb(t_list **stack)
{
	t_list	*node;
	t_list	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	node = tmp->next;
	tmp->next = NULL;
	node->next = *stack;
	*stack = node;
	write(1, "rrb\n", 4);
}

static void	srra(t_list **stack)
{
	t_list	*node;
	t_list	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	node = tmp->next;
	tmp->next = NULL;
	node->next = *stack;
	*stack = node;
}

static void	srrb(t_list **stack)
{
	t_list	*node;
	t_list	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	tmp = *stack;
	while (tmp->next->next)
		tmp = tmp->next;
	node = tmp->next;
	tmp->next = NULL;
	node->next = *stack;
	*stack = node;
}

void	rrr(t_list **stacka, t_list **stackb)
{
	srra(stackb);
	srrb(stacka);
	write(1, "rrr\n", 4);
}
