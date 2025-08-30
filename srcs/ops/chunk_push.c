/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:28:53 by manmaria          #+#    #+#             */
/*   Updated: 2025/08/29 14:09:53 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	ft_chunk_push(t_stack **a, t_stack **b, int s_size)
{
	t_chunk	chunki;
	int		target_chunk;

	chunki = ft_chunkinit(s_size);
	target_chunk = chunki.count - 1;
	while (s_size > 0 && target_chunk > 0)
	{
		ft_chunk_prep(a, target_chunk);
		if ((*a)->chunkid == target_chunk)
		{
			ft_stack_push(a, b, 0);
			ft_chunk_prep(a, target_chunk);
			s_size--;
		}
		else
			target_chunk--;
	}
}
