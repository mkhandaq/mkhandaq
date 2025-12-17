/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkhandaq <mkhandaq@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:26:18 by mkhandaq          #+#    #+#             */
/*   Updated: 2025/11/15 19:23:25 by mkhandaq         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_list;

void				sa(t_list **stack);
void				sb(t_list **stack);
void				ss(t_list **stacka, t_list **stackb);
void				rra(t_list **stack);
void				rrb(t_list **stack);
void				rrr(t_list **stacka, t_list **stackb);
void				ra(t_list **stack);
void				rb(t_list **stack);
void				rr(t_list **stacka, t_list **stackb);
void				pa(t_list **stacka, t_list **stackb);
void				pb(t_list **stackb, t_list **stacka);
void				radix(t_list **stacka, t_list **stackb);
void				push(t_list **stack, int value, int index);
void				setindex(t_list **stack);
void				totop(t_list **stacka);
void				handler(t_list **stacka, t_list **stackb, int size);

long long			ft_atoi(const char *nptr);
int					pop(t_list **stack);
int					main(int argc, char **argv);
int					*bblsort(t_list **stack);
int					ft_lstsize(t_list *lst);
int					check(char **argv);
int					check_dup(t_list **stack);
int					*setarr(t_list **stack);
int					issort(t_list **stack);
#endif