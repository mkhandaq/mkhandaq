/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sop.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:16:51 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/11/11 21:22:19 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	sa(t_list **stack)
{
	t_list	*head;
	t_list	*second;
	int		temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	second = (*stack)->next;
	temp = head->value;
	head->value = second->value;
	second->value = temp;
	write(1, "sa\n", 3);
}

void	sb(t_list **stack)
{
	t_list	*head;
	t_list	*second;
	int		temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	second = (*stack)->next;
	temp = head->value;
	head->value = second->value;
	second->value = temp;
	write(1, "sb\n", 3);
}

static void	ssa(t_list **stack)
{
	t_list	*head;
	t_list	*second;
	int		temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	second = (*stack)->next;
	temp = head->value;
	head->value = second->value;
	second->value = temp;
}

static void	ssb(t_list **stack)
{
	t_list	*head;
	t_list	*second;
	int		temp;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	head = *stack;
	second = (*stack)->next;
	temp = head->value;
	head->value = second->value;
	second->value = temp;
}

void	ss(t_list **stacka, t_list **stackb)
{
	ssa(stacka);
	ssb(stackb);
	write(1, "ss\n", 3);
}
