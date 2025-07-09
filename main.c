/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 21:12:40 by manmaria          #+#    #+#             */
/*   Updated: 2025/07/09 20:11:06 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_atoi(const char *s)
{
	int	sign;
	int	res;

	sign = 1;
	res = 0;
	while (*s == 32 || (*s >= 9 && *s<= 13))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign *= -1;
		s++;
	}
	while (*s >= '0' && *s <= '9')
	{
		res = res * 10 + *s - 48;
		s++;
	}
	return (res * sign);
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
		arr = malloc(sizeof(int) * (ac - 1));
		while (av[++i])
		{
			
		}
	}
	printf("\n");
	return (0);
}
