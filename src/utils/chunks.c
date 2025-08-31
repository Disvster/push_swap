/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:48:56 by manmaria          #+#    #+#             */
/*   Updated: 2025/08/31 15:41:19 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_chunk	ft_chunkinit(int stack_size)
{
	t_chunk	chunki;

	chunki.size = ft_sqrt_floor(stack_size);
	chunki.count = (stack_size + chunki.size - 1) / chunki.size;
	return (chunki);
}

int	ft_sqrt(int nb)
{
	int	low;
	int	high;
	int	mid;
	int	result;

	if (nb <= 1)
		return (nb == 1);
	low = 1;
	high = nb / 2;
	result = 0;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (mid * mid == nb)
			return (mid);
		else if (mid * mid < nb)
		{
			result = mid;
			low = mid + 1;
		}
		else
			high = mid - 1;
	}
	return (result);
}
