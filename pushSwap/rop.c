/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 17:04:14 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/11/13 15:44:54 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	ra(t_list **stack)
{
	t_list	*node;
	t_list	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	node = *stack;
	*stack = (*stack)->next;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->next = NULL;
	write(1, "ra\n", 3);
}

void	rb(t_list **stack)
{
	t_list	*node;
	t_list	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	node = *stack;
	*stack = (*stack)->next;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->next = NULL;
	write(1, "rb\n", 3);
}

static void	sra(t_list **stack)
{
	t_list	*node;
	t_list	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	node = *stack;
	*stack = (*stack)->next;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->next = NULL;
}

static void	srb(t_list **stack)
{
	t_list	*node;
	t_list	*tmp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	node = *stack;
	*stack = (*stack)->next;
	tmp = *stack;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = node;
	node->next = NULL;
}

void	rr(t_list **stacka, t_list **stackb)
{
	sra(stacka);
	srb(stackb);
	write(1, "rr\n", 3);
}
