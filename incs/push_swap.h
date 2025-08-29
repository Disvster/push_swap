/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:09:11 by manmaria          #+#    #+#             */
/*   Updated: 2025/08/27 16:38:55 by manmaria         ###   ########.fr       */
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
	int				cost;
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
void	ft_stack_addfront(t_stack **stack, t_stack *new_nd);
t_stack	*ft_stack_newnode(int value, int index, int chunk_size);
t_stack	*ft_stacklast(t_stack *lst);
void	ft_stack_clear(t_stack *lst);
t_chunk	ft_chunkinit(int stack_size);
char	ft_checksort(t_stack *s, int asc, int range);
int		ft_stack_size(t_stack *top);
t_stack	*ft_stack_middle(t_stack *start);

/*  Movement Functions  */
void	ft_stack_swap(t_stack **top);
void	ft_swap_both(t_stack **topa, t_stack **topb);
void	ft_stack_push(t_stack **topa, t_stack **topb, int which_stack);
void	ft_stack_rotate(t_stack **top,int which_stack);
void	ft_rotate_both(t_stack **topa, t_stack **topb);
void	ft_stack_revrotate(t_stack **top, int which_stack);
void	ft_revrotate_both(t_stack **topa, t_stack **topb);

/*  Operation Functions  */
void	ft_chunkcost(t_stack **top, t_stack **bot, int chunk);
void	ft_sendchunk(t_stack **a, int chunk);
void	ft_chunk_push(t_stack **a, t_stack **b, int s_size);

#endif
