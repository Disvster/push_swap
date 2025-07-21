/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:12:40 by manmaria          #+#    #+#             */
/*   Updated: 2025/07/13 17:06:09 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_sort_tab(long *tab, int size)
{
	int	i;
	int j;
	int	tmp;

	i = 0;
	j = 0;
	while (i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
				j = i;
			}
			else if (tab[i] == tab[j] || (tab[j] > INT_MAX || tab [j] < INT_MIN))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

long	*create_arr(int ac, char **av)
{
	long	*arr;
	int		i;
	char	check;

	i = 0;
	arr = malloc(sizeof(int) * (ac - 1));
	if (!arr)
		return (NULL);
	while (av[++i])
		arr[i - 1] = /*ft_*/atoi(av[i]); // FIX: atoi -> ft_atoi or ft_atol
	check = ft_sort_tab(arr, ac - 1);
	if (check == 0)
		return (0);
	return (arr);
}

/*	To test the sort int tab func	*/

	// printf("{");
	// i = 0;
	// while ((ac - 1) > 0)
	// {
	// 	printf("%d", arr[i++]);
	// 	if ((ac - 1) != 1)
	// 		printf(", ");
	// 	ac--;
	// }
	// printf("}\n");

t_stack	*create_sa(int ac, char **av, long *arr)
{
	int		size;
	t_stack	ola;

	size = ac;
	if (!arr)
		return (NULL);
	while (--size > 0)
	{
		t_stack
		// ill create the stack A list starting from the bottom and adding each new node
		// to the back of the previous
		// so for 4 Arguments:
		// node4 <- node3 <- node2 <- node1
	}
	//TODO:
	// depois de criar a stackA vou fazer um sort_int_tab no int array
	// tendo o array organizado, vou iterar cada node sob uma funcao que faz o nbr search
	// no array e atribuir um valor de index correto a esse node;
	// a funcao que cria o array pode organiza-lo logo, depois crio aqui a lista baseada no ac/av
	// como fiz para o array e imediatamento procuro pelo index, assim escuso de iterar pela lista
	// depois de a criar, faco tudo ao mesmo tempo instead.
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
	long *arr;
	// int	node;
	// int	i;
	//
	// node = 0;
	// i = 0;
	if (ac > 1)
	{
		arr = create_arr(ac, av);
		if (arr == 0 || !arr)
		{
			/*ft_*/printf("Error\n"); // FIX: printf -> ft_printf or maybe write to StdError
			return (1);
		}
		create_sa(ac, av, arr);
	}
	else 
		{
			/*ft_*/printf("Error\n"); // FIX: same as above
			return (1);
		}
	printf("\n");
	return (0);
}
