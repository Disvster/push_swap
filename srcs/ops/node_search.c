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

void	ft_chunkcost(t_stack **top, t_stack **bot, int chunk) // FIX: size
{
	int		ctop;
	int		cbot;
	t_stack *curr;
	
	ctop = 0;
	cbot = (ft_stack_size(*top) / 2) + 1;
	curr = *bot;
	if (!*top)
		return ;
	while (*top)
	{
		if ((*top)->chunkid == chunk || (*top)->next == *bot)
			break ;
		(*top) = (*top)->next;
		ctop += 1;
	}
	while (curr)
	{
		if (curr->chunkid == chunk || !curr->next)
			(*bot) = curr;
		curr = curr->next;
		cbot--;
	}
	(*top)->cost = ctop;                                                
	(*bot)->cost = cbot;
	if ((*top)->chunkid != chunk)  // NOTE: no protection if top->chunkid
		(*top)->cost = INT_MAX;                                                
	if ((*bot)->chunkid != chunk)  // NOTE: AND bot->chunkid are both != chunk
		(*bot)->cost = INT_MAX;
}
	// HACK: debug
	// if ((*bot)->chunkid == chunk || !(*bot)->next || cbot >= ctop)
	// ft_printf("\ntop = %p \nbot = %p\n", *top, *bot);
	// ft_printf("\ntop->cost = %d, bot->cost = %d\n", ctop, cbot);
	// ft_printf("\ntop->cost = %d, bot->cost = %d\n", (*top)->cost, (*bot)->cost);

void	ft_sendchunk(t_stack **a, t_stack **b, int chunk)
{
	t_stack	*top;
	t_stack	*bot;

	top = *a;
	bot = ft_stack_middle(*a);
	bot = bot->next;
	ft_chunkcost(&top, &bot, chunk);
	if (top->cost < bot->cost)
	{
		while (*a != top)
		{
			ft_stack_rotate(a, 0);
			// TODO: check here for rr
		}
	}
	else if (bot->cost < top->cost)
	{
		while (*a != bot)
		{
			ft_stack_revrotate(a, 0);
			// TODO: check here for rrr
		}
	}
	ft_stack_push(a, b, 0); // 0 is A
}
