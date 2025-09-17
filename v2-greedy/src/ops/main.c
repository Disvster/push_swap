/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:21:26 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/17 21:10:10 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

void	handle_big_sort(t_stack *a)
{
	t_stack	*b;
	int		c;

	b = NULL;
	c = -1;
	while (++c < 3)
		stack_push(&a, &b, 0);
	sort_three_b(&b);
	c = INT_MAX;
	while (a)
	{
		targets_to_top(&a, &b);
		stack_push(&a, &b, 0);
	}
	if (!a && b == find_highest(b))
	{
		while (b)
			stack_push(&b, &a, 1);
	}
	else if (!a)
		nodes_to_a(&a, &b);
}

void	handle_small_sort(t_stack *a, int size)
{
	t_stack	*b;

	b = NULL;
	if (size <= 3)
		sort_three_a(&a);
	else
		sort_five_a(&a, &b);
}

void	handle_stack(char **nav, long *tab, int size, char f)
{
	t_stack	*a;

	a = create_stack_a(size, nav, tab);
	if (!a)
	{
		write(2, "Error\n", 6);
		exit(write_error(&a, tab, nav, f));
	}
	if (check_sort(a, 0))
		return ;
	if (size <= 5)
		handle_small_sort(a, size);
	else
		handle_big_sort(a);
	if (check_sort(a, 0))
		handle_free(&a, tab, nav, f);
}

int	main(int ac, char **av)
{
	char	**nav;
	long	*tab;
	int		size;
	char	flag;

	flag = ac == 2;
	size = ac - 1;
	if (ac > 1)
	{
		if (ac == 2)
		{
			nav = ft_split(av[1], ' ');
			size = count_words(av[1], ' ');
			if (!nav)
				return (write_error(NULL, NULL, nav, flag));
		}
		else
			nav = ++av;
		tab = create_ltab(size, nav, flag);
		if (tab == 0 || !tab)
			return (write_error(NULL, tab, nav, flag));
		handle_stack(nav, tab, size, flag);
		return (0);
	}
	return (1);
}
