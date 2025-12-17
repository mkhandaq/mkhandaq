/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/05 20:49:17 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/11/15 19:22:41 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

int	*setarr(t_list **stack)
{
	int		listlen;
	int		i;
	int		*arr;
	t_list	*tmp;

	listlen = ft_lstsize(*stack);
	arr = malloc(sizeof(int) * listlen);
	if (!arr)
		return (NULL);
	tmp = *stack;
	i = 0;
	while (i < listlen)
	{
		arr[i] = tmp->value;
		tmp = tmp->next;
		i++;
	}
	return (arr);
}

int	*bblsort(t_list **stack)
{
	int	*arr;
	int	i;
	int	j;
	int	listlen;

	arr = setarr(stack);
	if (!arr)
		return (NULL);
	i = 0;
	listlen = ft_lstsize(*stack);
	while (i < listlen - 1)
	{
		j = 0;
		while (j < listlen - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
	return (arr);
}

void	setindex(t_list **stack)
{
	t_list	*tmp;
	int		*arr;
	int		i;
	int		len;

	len = ft_lstsize(*stack);
	arr = bblsort(stack);
	if (!arr)
		return ;
	tmp = *stack;
	while (tmp)
	{
		i = 0;
		while (i < len)
		{
			if (tmp->value == arr[i])
			{
				tmp->index = i;
				break ;
			}
			i++;
		}
		tmp = tmp->next;
	}
	free(arr);
}
