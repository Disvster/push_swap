/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/29 13:28:53 by manmaria          #+#    #+#             */
/*   Updated: 2025/08/31 16:56:06 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	ft_chunk_push(t_stack **a, t_stack **b, int s_size)
{
	t_chunk	chunki;
	int		i;

	i = 0;
	chunki = ft_chunkinit(s_size);
	while (/*s_size > chunki.size &&*/ i < chunki.count - 1)
	{
		ft_chunk_prep(a, b, i);
		if ((*a)->chunkid == i)
		{
			ft_stack_push(a, b, 0);
			ft_chunk_prep(a, b, i);
			s_size--;
		}
		else
			i++;
	}
}
