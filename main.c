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

int	*paramArr(int ac, char **av)
{
	int	*arr;
	int	node;
	int	i;

	node = 0;
	i = 0;
	arr = malloc(sizeof(int) * (ac - 1));
	if (!arr)
		return (NULL);
	while (av[++i])
		arr[i - 1] = ft_atoi(av[i - 1]);
	return (arr);
}

t_stack	*createStackA(int ac, char **av)
{
	int		*arr;
	int		size;
	t_stack ola;

	size = ac - 1;
	arr = paramArr(ac, av);
	if (!arr)
		return (NULL);
	while (--size >= 0)
	{
		// ill create the stack A list starting from the bottom and adding each new node
		// to the back of the previous
		// so for 4 Arguments:
		// node4 <- node3 <- node2 <- node1
	}
	// depois de criar a stackA vou fazer um sort_int_tab no int array
	// tendo o array organizado, vou iterar cada node sob uma funcao que faz o nbr search
	// no array e atribuir um valor de index correto a esse node;
	// a funcao que cria o array pode organiza-lo logo, depois crio aqui a lista baseada no ac/av
	// como fiz para o array e imediatamento procuro pelo index, assim escuso de iterar pela lista
	// depois de a criar, faco tudo ao mesmo tempo instead.
}

// TODO:
// In case of error, it must display "Error" followed by an ’\n’ on the standard error.
// Errors include, for example: some arguments not being integers, some arguments
// exceeding the integer limits, and/or the presence of duplicates.

int	main(int ac, char **av)
{
	int	*arr;
	int	node;
	int	i;

	node = 0;
	i = 0;
	if (ac > 1)
	{
	}
	printf("\n");
	return (0);
}
