/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/31 16:02:08 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/01 20:48:35 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

//top_a & bot_a ->cost has number of rot/revot needed to put them at the top
void	ft_handle_rot(t_stack **a, t_stack **b, t_stack **top)
{
	int	rota;

	rota = (*top)->cost;
	while (rota)
	{
		if (!ft_checksort(*b, 1, ft_stack_size(*b)))
		{
			if (ft_stack_size(*b) <= 3 && ft_tiny_sort_b(b) == 1)
				rota++;
			else
				ft_big_sort_b(b, rota, (*top)->chunkid, 1);
		}
		ft_rotate_both(a, b);
		rota--;
	}
}

void	ft_handle_revrot(t_stack **a, t_stack **b, t_stack **bot)
{
	int	reva;

	reva = (*bot)->cost;
	while (reva)
	{
		if (ft_tiny_sort_b(b) == -1)
			reva--;
		else
			ft_big_sort_b(b, &reva, (*bot)->chunkid, -1);
		
	}
}

int	ft_big_sort_b(t_stack **b, int *rot, int target_chunk, int direction)
{
	t_stack	*lowest;
	t_stack	*bot;
	t_stack	*top;
	int		nbr_of_rots_b_wants;

	top = *b;
	bot = ft_stack_middle(*b);
	bot = bot->next;
	lowest = ft_fdlowest(*b, target_chunk);
	nbr_of_rots_b_wants = 0;
	if (top->cost <= bot->cost && direction == 1)
		nbr_of_rots_b_wants += top->cost;
	else if (top->cost > bot->cost && direction == -1) // I want to rev rotate
		nbr_of_rots_b_wants += bot->cost;
}

// ok imma be honest
// idk what I'm doing here and I'm a bit drunk
// I wanted to send the lowest node to the bottom of the chunk
// but I got lost in the sauce;
// I could send the lowest to the bottom of the chunk then decrement on what the lowest (index) is
// like if I'm at chunk 4 and id's for chunk [4] are {6, 7, 8, 9}
// I search for 9 in B, if found then:
//	   is it better to rb or rrb
//	   if rb:
//			while (ra)
//				then rr
//			else
//				rb
//		else if (rrb)
//			send somehow to rrb
//
// if 9 not found then search for 8:
//		repeat process above until
//		index in chunk is found
//	if not found:
// if 9 (or 9--) == top of b then we want to put 8 at the top of B after 9
//	
//	idk I'm just riffing, somebody get the tabs
// 
//

void	ft_node_cost(t_stack **top, t_stack **bot, int lowest)
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
		if ((*top)->value == lowest || (*top)->next == *bot)
			break ;
		(*top) = (*top)->next;
		ctop += 1;
	}
	while (curr)
	{
		if (curr->value == lowest)
			(*bot) = curr;
		curr = curr->next;
		cbot--;
	}
	(*top)->cost = ctop;
	(*bot)->cost = cbot;
}

