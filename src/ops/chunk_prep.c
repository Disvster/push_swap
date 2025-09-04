/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_search.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/27 16:01:34 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/03 22:44:40 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	ft_chunk_cost(t_stack **top, t_stack **bot, int chunk)
{
	int		ctop;
	int		cbot;
	t_stack	*curr;

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
		if (curr->chunkid == chunk)
			(*bot) = curr;
		curr = curr->next;
		cbot--;
	}
	(*top)->cost = ctop;
	(*bot)->cost = cbot;
}

void	ft_chunk_prep(t_stack **a, t_stack **b, int chunk)
{
	t_stack	*top;
	t_stack	*bot;

	// if ((*a)->chunkid == chunk || ft_stack_size(*a) == 1)// FIX: incompatible with big_sort
	// 	return ;
	top = *a;
	bot = ft_stack_middle(*a);
	if (ft_stack_size(*a) > 3)// FIX: incompatible with big_sort
		bot = bot->next;
	ft_chunk_cost(&top, &bot, chunk);
	if (top->chunkid != chunk)
		top->cost = INT_MAX;
	if (bot->chunkid != chunk)
		bot->cost = INT_MAX;
	ft_chunk_sendtop(a, b, &top, &bot);
}

void	ft_chunk_sendtop(t_stack **a, t_stack **b, t_stack **top, t_stack **bot)
{
	(void)b;
	if ((*top)->cost == (*bot)->cost && (*top)->cost == INT_MAX)
		return ;
	if ((*top)->cost <= (*bot)->cost)
	{
		// while (*a != (*top))//ra
		// {
		// if (!ft_checksort(*b, 0, ft_stack_size(*b)))
			ft_big_sort(a, b, *top, 1);
		// else
		// {
		// 	while (*a != (*top))//ra
		// 		ft_stack_rotate(a, 0);
		// 	ft_stack_push(a, b, 0);
		// }
	}
	else if ((*bot)->cost < (*top)->cost)
	{
		// while (*a != (*bot))//rb
		// {
		// if (!ft_checksort(*b, 0, ft_stack_size(*b)))
			ft_big_sort(a, b, *bot, 0);
		// else
		// 	ft_stack_revrotate(a, 0);
		// // }
	}
}
// HACK: debug chunkcost
// if ((*bot)->chunkid == chunk || !(*bot)->next || cbot >= ctop)
// ft_printf("\ntop = %p \nbot = %p\n", *top, *bot);
// ft_printf("\ntop->cost = %d, bot->cost = %d\n", ctop, cbot);
// ft_printf("\ntop->cost = %d, bot->cost = %d\n", (*top)->cost,
// (*bot)->cost);
// HACK: debug prepchunk
// ft_printf("-----> TOP value -> %d, in chunk -> %d\n",
// top->value, top->chunkid);
// ft_printf("-----> BOT1 value -> %d, in chunk -> %d\n",
// bot->value, bot->chunkid);
// ft_printf("-----> top cost -> %d, bot cost -> %d\n", top->cost, bot->cost);
// TODO: check here for rr
// check if ft_sortb wants to rotate as well
// if it does then (rr)
// if either one finishes rotating first:
//		if b: b is sorted, exit ft_sortb
//		if a: finish sort in b, exit ft_sortb
// if it doesnt then (rrb) until b is sorted then exit
// TODO: check here for rrr
// check if ft_sortb wants to rev rotate as well
// if it does then (rrr)
// if either one finishes rotating first:
//		if b: b is sorted, exit ft_sortb
//		if a: finish sort in b, exit ft_sortb
// if it doesnt then (rb) until b is sorted then exit
