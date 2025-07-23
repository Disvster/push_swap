/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:12:40 by manmaria          #+#    #+#             */
/*   Updated: 2025/07/23 18:19:08 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	**create_stack_a(int ac, char **av, long *arr)
{
	int			size;
	int			nbr;
	int			node_id;
	t_stack		**stack_a;
	t_stack		*new_nd;

	size = ac;
	while (--size > 0)
	{
		nbr = /*ft*/atoi(av[size]);
		node_id = ft_find_index(arr, ac - 1, nbr);
		new_nd = stack_newnode(nbr, node_id);
		if (!new_nd || node_id == -1)
			return (NULL);
		*stack_a = new_nd;
		stack_add_front(stack_a, new_nd);
		// creating the stack A in reverse and adding each new node;
		// so for 4 Arguments:
		// 1st-node3 -> size-- -> 2nd-node2 -> size-- -> 3rd-node1
	}
	return (stack_a);
}
//
// // TODO:
// In case of error, it must display "Error" followed by an ’\n’ on the standard error.
// Errors include, for example: !some arguments not being integers!, -some arguments
// exceeding the integer limits-, -and/or the presence of duplicates-.

/*
 * After Stack A is created I can organize each node according to where they are vs where they should be.
 * I iterate through the stack and compare the real index of where they are (`i`) with the value stored as
 * `final_index`.
 * I can also send bunches of nodes to stack B, organized them there and send them back to A, then do
 * the same again but instead of a bunch of nodes send a bunch of buches of organized nodes.
 * Like start with (idk) 3 (I heard that 3 is hard-coded) nodes to B, organize them there. ex:
 * 5-6-7 then 2-3-4 then 8-9-10
 * Then :
 * (2-3-4)-(5-6-7)-(8-9-10)
 */

int	main(int ac, char **av)
{
	long *ltab;
	// int	node;
	// int	i;
	//
	// node = 0;
	// i = 0;
	if (ac > 1)
	{
		ltab = create_ltab(ac, av);
		if (ltab == 0 || !ltab)
		{
			/*ft_*/printf("Error\n"); // FIX: printf -> ft_printf or maybe write to StdError
			return (1);
		}
		create_sa(ac, av, ltab);
	}
	else 
		{
			/*ft_*/printf("Error\n"); // FIX: same as above
			return (1);
		}
	printf("\n");
	return (0);
}
