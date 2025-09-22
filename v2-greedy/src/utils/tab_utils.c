/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tab_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 16:54:14 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/12 07:09:45 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

int	ft_atol(const char *nptr)
{
	int		i;
	int		sign;
	long	res;

	i = 0;
	res = 0;
	sign = 1;
	while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res = res * 10 + (nptr[i] - 48);
		i++;
	}
	return (res * sign);
}

int	ft_sort_ltab(long *tab, int size)
{
	int	i;
	int	j;
	int	tmp;

	i = -1;
	j = 0;
	while (++i < (size - 1))
	{
		j = i + 1;
		while (j < size)
		{
			if (tab[i] == tab[j] || tab[j] > INT_MAX || tab [j] < INT_MIN
				|| tab[i] > INT_MAX || tab [i] < INT_MIN)
				return (0);
			if (tab[i] > tab[j])
			{
				tmp = tab[i];
				tab[i] = tab[j];
				tab[j] = tmp;
				j = i;
			}
			j++;
		}
	}
	return (1);
}

char	check_validarg(char *s)
{
	size_t	i;

	i = 0;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	if (s[i] == '+' || s[i] == '-')
		i++;
	while (ft_isdigit(s[i]))
		i++;
	while (s[i] == 32 || (s[i] >= 9 && s[i] <= 13))
		i++;
	return (i == ft_strlen(s));
}

long	*create_ltab(int ac, char **av, char flag)
{
	long	*ltab;
	int		i;
	char	check;

	i = -1;
	ltab = malloc(sizeof(long) * ac);
	if (!ltab)
		return (NULL);
	while (av[++i])
	{
		if (check_validarg(av[i]) == 0)
			exit(write_error(NULL, ltab, av, flag));
		ltab[i] = ft_atol(av[i]);
	}
	check = ft_sort_ltab(ltab, ac);
	if (check == 0)
		exit (write_error(NULL, ltab, av, flag));
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

int	find_index(long *tab, int size, int nbr)
{
	int	low;
	int	mid;	
	int	high;

	low = 0;
	high = size - 1;
	while (low <= high)
	{
		mid = low + (high - low) / 2;
		if (tab[mid] == nbr)
			return (mid);
		else if (nbr > tab[mid])
			low = mid + 1;
		else if (nbr < tab[mid])
			high = mid - 1;
	}
	return (-1);
}
