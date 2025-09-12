/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 14:21:26 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/12 07:13:38 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "testing.h"
#include "push_swap.h"

t_stack	*get_lesscost(t_stack *s)
{
	t_stack	*target;
	t_stack	*temp;

	temp = s;
	target = NULL;
	while (temp)
	{
		if (temp->mov > 0 && temp->target->mov >  0)
			temp->cost = ft_max(temp->mov, temp->target->mov);
		else if (temp->mov < 0 && temp->target->mov < 0)
			temp->cost = ft_max(ft_abs(temp->mov), ft_abs(temp->target->mov));
		else if (temp->mov < 0 && temp->target->mov > 0)
			temp->cost = ft_abs(temp->mov) + temp->target->mov;
		else if (temp->mov > 0 && temp->target->mov < 0)
			temp->cost = temp->mov + ft_abs(temp->target->mov);
		if (!target || (temp->cost < target->cost))
			target = temp;
		temp = temp->next;
	}
	return (target);
}

void	set_target(t_stack *a, t_stack *b, char w)
{
	t_stack	*target;
	t_stack	*temp;

	if (!a || !b)
		return ;
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
		return ;
	temp = s;
	size = ft_stack_size(s);
	i = 0;
	while (temp)
	{
		if (i <= size / 2)
			temp->mov = i;
		else
			temp->mov = i - size;
		temp = temp->next;
		i++;
	}
}

void	big_bones(t_stack **sa, t_stack **sb, int *pc)
{
	t_stack *a;
	t_stack *b;
	t_stack	*targa;
	int		c;

	c = 0;
	a = *sa;
	b = *sb;
	set_mov(a);
	set_mov(b);
	set_target(a, b, 'a');
	targa = get_lesscost(a);
	// INFINITE LOOP HEREEEEE
	c = targa->cost;
	while (a != targa || b != targa->target)// FIX: size
	{
		if (targa->mov > 0 && targa->target->mov > 0)
			stack_rr(&a, &b);
		else if (targa->mov < 0 && targa->target->mov < 0)
			stack_rrr(&a, &b);
		else
		{
			if (targa->mov > 0)
				stack_rotate(&a, 0);
			if (targa->target->mov > 0)
				stack_rotate(&b, 1);
			if (targa->mov < 0)
				stack_revrotate(&a, 0);
			if (targa->target->mov < 0)
				stack_revrotate(&b, 1);
		}
		c--;
	}
	*pc = c;
}

void	handle_big_sort(t_stack *a)
{
	t_stack *b;
	int		c;

	b = NULL;
	c = -1;
	while (++c < 3)
		stack_push(&a, &b, 0);
	while (a)
	{
		big_bones(&a, &b, &c);
		stack_push(&a, &b, 0);
		mini_print_stacks(&a, &b);
	}
	if (!a)
		return ;
}

void	handle_small_sort(t_stack *a, int size)
{
	t_stack	*b;
	
	b = NULL;
	if (size <= 3)
		sort_three_a(&a);
	else
		sort_five_a(&a, &b);
	return ;
}

void	handle_stack(char **nav, long *tab, int size, char f)
{
	t_stack *a;
	
	a = create_stack_a(size, nav, tab);
	if (!a)
	{
		write(2, "Error\n", 6);
		exit(handle_free(&a, tab, nav, f));
	}
	mini_print_stacks(&a, NULL);
	if (check_sort(a, 0))
	{
		ft_printf("stack is sorted in ascending order\n");
		return ;
	}
	else
		ft_printf("stack is not sorted\n");
	if (size <= 5)
		handle_small_sort(a, size);
	else
		handle_big_sort(a);
	if (check_sort(a, 0))
	{
		ft_printf("stack is sorted in ascending order\n");
		handle_free(&a, tab, nav, f);
		return ;
	}
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
			if (!nav){
				write(2, "Error\n", 6);
				return (handle_free(NULL, NULL, nav, flag));}
		}
		else
			nav = ++av;
		tab = create_ltab(size, nav, flag);
		if (tab == 0 || !tab)
		{
			write(2, "Error\n", 6);
			return (handle_free(NULL, tab, nav, flag));
		}
		handle_stack(nav, tab, size, flag);
		return (0);
	}
	else
		return (1);
}
