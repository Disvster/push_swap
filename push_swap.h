/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:09:11 by manmaria          #+#    #+#             */
/*   Updated: 2025/07/23 18:12:10 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "libft/incs/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	struct s_stack	*next;
}					t_stack;

int		ft_find_index(long *tab, int size,int nbr);
int		ft_sort_ltab(long *tab, int size);
long	*create_ltab(int ac, char **av);

void	stack_add_front(t_stack **stack, t_stack *new_nd);
t_stack	*stack_newnode(int	value, int index);

#endif
