/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:21:26 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/07 14:21:31 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_small_sort(t_stack *a, int size)
{
	t_stack	*b;
	
	b = NULL;
	if (size <= 3)
		sort_three_a(&a);
	else
		sort_five_b(&a, &b);
	return ;
}

void	handle_stack(char **nav, t_chunk chunki, long *arr, int size)
{
	t_stack *a;
	
	a = create_stack_a(size, nav, arr, chunki);
	if (!a)
	{
		write(2, "Error\n", 6);
		handle_free(a, arr);// TODO:
		exit(1);
	}
	if (check_sort(a, 0))
	{
		ft_printf("stack is sorted in ascending order\n");// HACK:
		handle_free(a, arr);// TODO:
		exit(0);
	}
	else
		ft_printf("stack is not sorted\n");// HACK:
	if (size <= 5)
		handle_small_sort(a, size);
	else
		handle_big_sort(a, size);
	if (check_sort(a, 0))
	{
		ft_printf("stack is sorted in ascending order\n");// HACK:
		handle_free(a, arr);// TODO:
		exit(0);
	}
}

int	main(int ac, char **av)
{
	char	**nav;
	long	*arr;
	int		size;
	t_chunk	chunki;

	size = ac - 1;
	if (ac > 1)
	{
		if (ac == 2)
			nav = ft_split(av[1], ' ');
		else
			nav = av;
		arr = create_ltab(size, nav);
		if (arr == 0 || !arr)
		{
			write(2, "Error\n", 6);
			return (1);
		}
		chunki = ft_chunkinit(size);
		handle_stack(nav, chunki, arr, size);
	}
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
}
