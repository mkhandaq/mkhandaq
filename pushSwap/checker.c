/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 15:37:59 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/11/15 19:08:15 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static int	check_char(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-')
		i++;
	if ((str[i] == '+' || str[i] == '-') && !str[i + 1])
		return (0);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			break ;
		i++;
	}
	if (str[i] == '\0')
		return (1);
	return (0);
}

static int	check_overflow(const char *str)
{
	long long	nbr;

	nbr = ft_atoi(str);
	if (nbr > 2147483647 || nbr < -2147483648)
		return (0);
	return (1);
}

int	check_dup(t_list **stack)
{
	int	*arr;
	int	i;
	int	j;
	int	len;

	arr = bblsort(stack);
	len = ft_lstsize(*stack);
	i = 0;
	j = 0;
	while (i < len - 1)
	{
		if (arr[i] == arr[i + 1])
		{
			free(arr);
			return (0);
		}
		i++;
	}
	free(arr);
	return (1);
}

int	check(char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if (!check_char(argv[i]) || !check_overflow(argv[i]))
			return (0);
		i++;
	}
	return (1);
}
