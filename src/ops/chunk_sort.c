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
void	ft_handle_rot(t_stack **a, t_stack **b, t_stack **top_a)
{
	int	rota;

	rota = (*top_a)->cost;

	while (rota--)
	{
		if (!ft_checksort(*b, 1, ft_stack_size(*b)))
			
		ft_rotate_both(a, b);
	}
}

void	ft_handle_revrot(t_stack **a, t_stack **b, t_stack **bot_a)
{
	int	reva;

	reva = (*bot_a)->cost;

	while (reva--)
	{
		if (!ft_checksort(*b, 1, ft_stack_size(*b)))

		ft_revrotate_both(a, b);
	}
}
