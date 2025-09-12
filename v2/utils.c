/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:16:33 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/10 20:25:27 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_abs(int nb)
{
	if (nb >= 0)
		return (nb);
	else
		return (nb * -1);
}

int	ft_max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	handle_free(t_stack **a, long *tab, char **nav)
{
	if (a)
		ft_stack_clear(*a);
	if (nav)
		free_split(nav);
	if (tab)
		free(tab);
	write(2, "Error\n", 6);
	return (1);
}
