/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 20:16:33 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/12 07:04:49 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

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

int	handle_free(t_stack **a, long *tab, char **nav, char f)
{
	if (a)
		ft_stack_clear(*a);
	if (nav && f)
	{
		free_split(nav);
		nav = NULL;
	}
	if (tab)
	{
		free(tab);
		tab = NULL;
	}
	return (1);
}
