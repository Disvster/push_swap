/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:12:40 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/02 16:59:19 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/push_swap.h"
#include "incs/testing.h"

int	main(int ac, char **av)
{
	long		*ltab;
	t_stack		*sa;
	t_stack		*b;
	// t_stack		*tmp;
	t_chunk		c;
	// t_stack		**pa;
	// t_stack		**pb = NULL;

	if (ac > 1)
	{
		ltab = ft_create_ltab(ac, av);
		if (ltab == 0 || !ltab)
		{
			//printf("Error\n");
			write(2, "Error\n", 6);
			return (1);
		}
		c = ft_chunkinit(ac - 1);
		sa = ft_create_stack_a(ac, av, ltab, c);
		if (!sa)
			return (1);
		// pa = &sa;
		// test_movements(pa);
		// print_stack(&sa);
		b = NULL;
		mini_print_stacks(&sa, &b);

		/* STACK DIVISION TESTING */
		// ft_printf("\nmiddle node:\n");
		// tmp = ft_stack_middle(sa);
		// ft_printf("value -> %d\nindex -> %d\nin chunk -> %d\n\n", tmp->value, tmp->index, tmp->chunkid);

		/* SORT CHECK TESTING */
		if (ft_checksort(sa, 0, ac - 1))
			ft_printf("stack is sorted in ascending order\n");
		else if (ft_checksort(sa, 1, ac - 1))
			ft_printf("stack is sorted in descending order\n");
		else
			ft_printf("stack is not sorted\n");

		/* CHUNK PUSH TO B TESTING */
		// int chunk = ft_sqrt_floor(ac - 1) - 1;
		// ft_printf("\nchunki.size = %d , chunki.count = %d\n", c.size, c.count);
		int	size_a = ft_stack_size(sa);
		if (size_a <= 5)
		{
			if (size_a > 3)
				ft_sort_five_a(&sa, &b);
			else
				ft_tiny_sort_a(&sa);
			mini_print_stacks(&sa, &b);
			return (0);
		}
		if (ft_checksort(sa, 0, ac - 1))
		{
			ft_printf("\nstack is sorted in ascending order\n");
		}
		ft_chunk_push(&sa, &b, ac - 1);
		ft_printf("%d Node(s) from chunk [%d] was pushed to B\n",
			ft_stack_size(b), c.count - 1);
		// ft_printf("\nStack B:\n");
		// print_stack(&b);
		// ft_printf("\nStack A:\n");
		// print_stack(&sa);
		mini_print_stacks(&sa, &b);
		for (int i = 0, s = ft_stack_size(b); i < s; i++)
			ft_stack_push(&b, &sa, 1);
		mini_print_stacks(&sa, &b);
		
		// ft_printf("for chunk [%d] cheapest node is:\n", ft_sqrt_floor(ac - 1) - 1);
		// ft_printf("value -> %d\nindex -> %d\nin chunk -> %d\n\n", tmp->value, tmp->index, tmp->chunkid);

		free(ltab);
		ft_stack_clear(sa);
		if (b)
			ft_stack_clear(b);
	}
	else
	{
		write(2, "Error\n", 6);
		return (1);
	}
	printf("\n");
	return (0);
}
