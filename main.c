/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:12:40 by manmaria          #+#    #+#             */
/*   Updated: 2025/08/29 14:08:28 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incs/push_swap.h"
#include "incs/testing.h"

t_stack	*create_stack_a(int ac, char **av, long *arr)
{
	int			size;
	int			nbr;
	int			node_id;
	t_stack		*new_nd;
	t_stack		*temp;
	t_chunk		chunki;

	size = ac;
	temp = NULL;
	new_nd = NULL;
	chunki = ft_chunkinit(size - 1);
	ft_printf("\nchunki.size = %d , chunki.count = %d\n", chunki.size, chunki.count);
	while (--size > 0)
	{
		nbr = ft_atoi(av[size]);
		node_id = ft_find_index(arr, ac - 1, nbr);
		temp = ft_stack_newnode(nbr, node_id, chunki.size);
		if (!temp || node_id == -1)
			return (NULL);
		if (new_nd)
			temp->next = new_nd;
		new_nd = temp;
	}
	return (new_nd);
}
	// above I'm creating the stack A in reverse and adding each new node;
	// so for 4 Arguments: 1st-node3 -> size-- -> 2nd-node2 -> size-- -> 3rd-node1

// TODO:
// In case of error, it must display "Error" followed by an ’\n’ on the standard error.
// Errors include, for example: !some arguments not being integers!, -some arguments
// exceeding the integer limits-, -and/or the presence of duplicates-.

int	main(int ac, char **av)
{
	long		*ltab;
	t_stack		*sa;
	t_stack		*b;
	t_stack		*tmp;
	// t_stack		**pa;
	// t_stack		**pb = NULL;

	if (ac > 1)
	{
		ltab = create_ltab(ac, av);
		if (ltab == 0 || !ltab)
		{
			//printf("Error\n");
			write(2, "Error\n", 6);
			return (1);
		}
		sa = create_stack_a(ac, av, ltab);
		if (!sa)
			return (1);
		// pa = &sa;
		// test_movements(pa);
		// print_stack(&sa);
		mini_print_stacks(&sa, &b);

		/* STACK DIVISION TESTING */
		ft_printf("\nmiddle node:\n");
		tmp = ft_stack_middle(sa);
		ft_printf("value -> %d\nindex -> %d\nin chunk -> %d\n\n", tmp->value, tmp->index, tmp->chunkid);

		/* SORT CHECK TESTING */
		if (ft_checksort(sa, 1, ac - 1))
			ft_printf("stack is sorted in ascending order\n");
		else if (ft_checksort(sa, 0, ac - 1))
			ft_printf("stack is sorted in descending order\n");
		else
			ft_printf("stack is not sorted\n");

		/* CHUNK PUSH TO B TESTING */
		b = NULL;
		// int chunk = ft_sqrt_floor(ac - 1) - 1;
		t_chunk c = ft_chunkinit(ac - 1);
		ft_chunk_push(&sa, &b, ac - 1);
		ft_printf("%d Node(s) from chunk [%d] was pushed to B\n",
			ft_stack_size(b), c.count - 1);
		// ft_printf("\nStack B:\n");
		// print_stack(&b);
		// ft_printf("\nStack A:\n");
		// print_stack(&sa);
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
