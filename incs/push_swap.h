/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:09:11 by manmaria          #+#    #+#             */
/*   Updated: 2025/08/22 20:16:04 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include "../libft/incs/libft.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				chunkid;
	struct s_stack	*next;
}					t_stack;

typedef struct s_chunk
{
	int	size;
	int	count;
}				t_chunk;

/*  Array Related Functions  */
int		ft_find_index(long *tab, int size, int nbr);
int		ft_sort_ltab(long *tab, int size);
long	*create_ltab(int ac, char **av);
int		ft_find_index(long *tab, int size, int nbr);

int		ft_sqrt_floor(int nb);


/*  Stack Related Functions  */
void	stack_add_front(t_stack **stack, t_stack *new_nd);
t_stack	*stack_newnode(int value, int index, int chunk_size);
t_stack	*ft_stacklast(t_stack *lst);
void	ft_stack_clear(t_stack *lst);
t_chunk	ft_chunkinit(int stack_size);
int	ft_check_sort(t_stack *s, long *tab, int asc, int range);

/*  Movements/Operations Functions  */
t_stack	**ft_stack_swap(t_stack **top);
void	ft_swap_both(t_stack **topa, t_stack **topb);
t_stack	**ft_stack_push(t_stack **topa, t_stack **topb);
t_stack	**ft_stack_rotate(t_stack **top);
void	ft_rotate_both(t_stack **topa, t_stack **topb);
t_stack	**ft_stack_revrotate(t_stack **top);
void	ft_revrotate_both(t_stack **topa, t_stack **topb);

#endif
