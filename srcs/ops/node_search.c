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

t_stack	*ft_targetnode(t_stack *start, int chunk)
{
	t_stack *top;
	t_stack *bot;
	int		ctop;
	int		cbot;
	
	if (!start)
		return (NULL);
	ctop = 0;
	cbot = 1;
	top = start;
	bot = ft_stack_middle(start);
	bot = bot->next;
	while (top)
	{
		if (top->chunkid == chunk || top->next == bot)
			break ;
		top = top->next;
		ctop++;
	}
	while (bot)
	{
		if (bot->chunkid == chunk && !bot->next)
			break ;
		bot = bot->next;
		cbot++;
	}
	if (ctop <= cbot && top->chunkid == chunk)
		return (top);
	else if (cbot < ctop && bot->chunkid == chunk)
		return (bot);
	return (start);
}
