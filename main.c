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

t_stack	*create_stack_a(int ac, char **av, long *arr)
{
	int			size;
	int			nbr;
	int			node_id;
	t_stack		*new_nd;
	t_stack		*temp;

	size = ac;
	temp = NULL;
	new_nd = NULL;
	while (--size > 0)
	{
		nbr = /*ft*/atoi(av[size]);
		node_id = ft_find_index(arr, ac - 1, nbr);
		temp = stack_newnode(nbr, node_id);
		if (!temp || node_id == -1)
			return (NULL);
		if (new_nd)
			temp->next = new_nd;
		new_nd = temp;
		// stack_add_front(stack_a, temp);
		// creating the stack A in reverse and adding each new node;
		// so for 4 Arguments: 1st-node3 -> size-- -> 2nd-node2 -> size-- -> 3rd-node1
	}
	free(arr);
	return (new_nd);
}

// // TODO:
// In case of error, it must display "Error" followed by an ’\n’ on the standard error.
// Errors include, for example: !some arguments not being integers!, -some arguments
// exceeding the integer limits-, -and/or the presence of duplicates-.


/* ---TEST--- <> -FUNCTIONS- */

void	print_st(t_stack **st)
{
	int		i;
	t_stack *tmp;

	if (!st || !*st)
	{
		printf("Stack is empty\n");
		return ;
	}
	i = 0;
	tmp = *st;
	while (tmp)
	{
		//value -> %d\n // before index
		printf("node[%d]:\nindex -> %d", i, tmp->index);
		i++;
		tmp = tmp->next;
		if (tmp)
			printf("\n");
	}
}

void	test_movements(t_stack	**pa)
{
	t_stack	**tmp_a;
	t_stack	**tmp_b;

	tmp_a = pa;
	tmp_b = NULL;
	// NORMAL STACK
	printf("\n-*-*-*-*-*-*-\n==> Before Movements:\n\n-< Stack A >-\n");
	print_st(pa);
	printf("\n\n-< Stack B >-\n");
	print_st(tmp_b);
	
	// SWAP A
	printf("-*-*-*-*-*-*-\n\n-*-*-<sa>-*-*-\n==> After SwapA:\n");
	pa = ft_stack_swap(tmp_a);
	printf("\n-< Stack A >-\n");
	print_st(pa);

	// ROTATE A (1st goes last)
	printf("\n\n-*-*-<ra>-*-*-\n==> After Rotate A (1st goes last):\n");
	pa = ft_stack_rotate(tmp_a);
	printf("\n-< Stack A >-\n");
	print_st(pa);
	printf("\n-*-*-<ra>-*-*-\n");
	
	//REVERSE ROTATE A (last goes 1st)
	printf("\n-*-*-<rra>-*-*-\n==> After Reverse Rotate A (last goes 1st):\n");
	pa = ft_stack_revrotate(tmp_a);
	printf("\n-< Stack A >-\n");
	print_st(pa);
	printf("\n-*-*-<ra>-*-*-\n");

	// PUSH A (b -> a)
	printf("\n-*-*-<sa>-*-*-\n\n-*-*-<pa>-*-*-\n==> After Push (top of B to) A:\n");
	pa = ft_stack_push(tmp_a, tmp_b);
	printf("\n-< Stack A >-\n");
	print_st(pa);
	printf("\n\n-< Stack B >-\n");
	print_st(tmp_b);

	//PUSH B (a -> b)
	printf("-*-*-<pa>-*-*-\n\n-*-*-<pb>-*-*-\n==> After Push (top of A to) B:\n");
	tmp_b = ft_stack_push(tmp_b, tmp_a);
	printf("\n-< Stack A >-\n");
	print_st(pa);
	printf("\n\n-< Stack B >-\n");
	print_st(tmp_b);
	printf("\n-*-*-<pb>-*-*-\n");
}

/* ---------- <> ---------- */

int	main(int ac, char **av)
{
	long		*ltab;
	t_stack		*sa;
	t_stack		**pa;

	if (ac > 1)
	{
		ltab = create_ltab(ac, av);
		if (ltab == 0 || !ltab)
		{
			//printf("Error\n");
			write(1, "Error\n", 6);
			return (1);
		}
		sa = create_stack_a(ac, av, ltab);
		if (!sa)
			return (1);
		pa = &sa;
		test_movements(pa);
		ft_stack_clear(pa);
	}
	else 
	{
		write(2, "Error\n", 6);
		return (1);
	}
	printf("\n");
	return (0);
}
