/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 19:42:06 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/03 20:29:01 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

void	ft_add(int *pi)
{
	printf("tab[0] = %d\n", pi[0]);
	*pi += 1;
	printf("tab[0] = %d\n", *pi);
	pi += 1;
	printf("tab[0] = %d\n", pi[0]);
	*pi += 1;
	printf("tab[0] = %d\n", *pi);
}

int	main(void)
{
	int	i;
	int *tab;

	tab = malloc(sizeof(int) * 2);
	i = 1;
	tab[0] = i;
	tab[1] = 42;
	printf("*tab = %d\n", *tab);
	ft_add(tab);
	printf("*tab = %d\n", *tab);
	tab += 1;
	printf("*tab = %d\n", *tab);
}
