/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:21:26 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/09 06:05:39 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*get_lesscost(t_stack *s)
{
	t_stack	*target;
	t_stack	*temp;

	target = NULL;
	temp = s;
	while (temp)
	{
		//if (double neg || double pos)
		//	get_max(abs1, abs2)
		//else
		//	ft_max(abs1, abs2)
	}
}

void	set_target(t_stack *a, t_stack *b, char w)
{
	t_stack	*target;
	t_stack	*temp;

	if (!a || !b)
		exit(1);// HACK:
	target = NULL;
	if (w == 'a')
		temp = a;
	else
		temp = b;
	while (temp)
	{
		if (w == 'a')
			target = find_nextlowest(b, temp);
		else if (w == 'b')
			target = find_nexthighest(a, temp);
		temp->target = target;
		temp = temp->next;
	}
}

void	set_mov(t_stack *s)
{
	t_stack	*temp;
	int		i;
	int		size;

	if (!s)
		return ;// HACK:
	temp = s;
	size = ft_stack_size(s);
	i = 0;
	while (temp)
	{
		if (i <= size / 2)
			temp->cost = i;
		else
			temp->cost = i - size;
		temp = temp->next;
		i++;
	}
}

void	handle_big_sort(t_stack *a, int size)
{
	t_stack *b;

	b = NULL;
}

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
