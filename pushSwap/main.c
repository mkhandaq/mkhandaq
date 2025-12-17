/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/09 18:52:44 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/11/16 17:26:19 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	setstack(t_list **stack, char **argv, int argc)
{
	int	val;

	argc--;
	while (argc > 0)
	{
		val = ft_atoi(argv[argc]);
		push(stack, val, 0);
		argc--;
	}
}

static void	freestack(t_list **stack)
{
	t_list	*tmp;

	tmp = *stack;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

int	issort(t_list **stack)
{
	int	*arr;
	int	len;
	int	i;

	arr = setarr(stack);
	len = ft_lstsize(*stack);
	i = 0;
	while (i < len - 1)
	{
		if (arr[i] > arr[i + 1])
		{
			free(arr);
			return (0);
		}
		i++;
	}
	free(arr);
	return (1);
}

int	main(int argc, char **argv)
{
	t_list	*stacka;
	t_list	*stackb;
	int		len;

	stacka = NULL;
	stackb = NULL;
	if (argc == 1)
		return (0);
	if (!check(argv))
	{
		write(2, "Error\n", 6);
		return (1);
	}
	setstack(&stacka, argv, argc);
	if (!check_dup(&stacka))
	{
		write(2, "Error\n", 6);
		freestack(&stacka);
		return (1);
	}
	setindex(&stacka);
	len = ft_lstsize(stacka);
	handler(&stacka, &stackb, len);
	freestack(&stacka);
	freestack(&stackb);
}
