/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:54:14 by manmaria          #+#    #+#             */
/*   Updated: 2025/07/23 18:04:52 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_sort_ltab(long *tab, int size)
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

long	*create_ltab(int ac, char **av)
{
	long	*ltab;
	int		i;
	char	check;

	i = 0;
	ltab = malloc(sizeof(int) * (ac - 1));
	if (!ltab)
		return (NULL);
	while (av[++i])
		ltab[i - 1] = /*ft_*/atol(av[i]); // FIX: atol -> ft_atol
	check = ft_sort_ltab(ltab, ac - 1);
	if (check == 0)
		return (0);
	return (ltab);
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

int	ft_find_index(long *tab, int size,int nbr)
{
	int		i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == nbr)
			return (i);
		i++;
	}
	return (-1);
}
