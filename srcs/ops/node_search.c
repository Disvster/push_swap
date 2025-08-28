/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:01:34 by manmaria          #+#    #+#             */
/*   Updated: 2025/08/27 16:58:45 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	ft_chunkcost(t_stack **midup, t_stack **midown, int chunk)
{
	t_stack *top;
	t_stack *bot;
	
	if (!*midup || !*midown)
		return ;
	top = *midup;
	bot = *midown;
	while (top)
	{
		if (top->chunkid == chunk || top->next == bot)
			break ;
		top = top->next;
		top->cost++;
	}
	while (bot)
	{
		if (bot->chunkid == chunk || !bot->next)
			break ;
		bot = bot->next;
		bot->cost++;
	}
	if (top->chunkid != chunk)  // NOTE: no protection if top->chunkid
		top->cost = INT_MAX;                                                
	if (bot->chunkid != chunk)  // NOTE: AND bot->chunkid are both != chunk
		bot->cost = INT_MAX;
}

void	ft_sendchunk(t_stack **a, t_stack **b, int chunk) // FIX: size
{
	t_stack	*top;
	t_stack	*bot;

	top = *a;
	bot = ft_stack_middle(*a);
	bot = bot->next;
	top->cost = 0;
	bot->cost = 1;
	ft_chunkcost(&top, &bot, chunk);
	if (top->cost < bot->cost)
	{
		while (*a != top)
		{
			ft_stack_rotate(a);
			// TODO: check here for rr
			ft_printf("ra\n");
		}
	}
	else if (bot->cost < top->cost)
	{
		while (*a != bot)
		{
			ft_stack_revrotate(a);
			// TODO: check here for rrr
			ft_printf("rra\n");
		}
	}
	ft_stack_push(a, b);
}
