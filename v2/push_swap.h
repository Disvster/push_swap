/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:09:11 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/08 22:53:06 by manmaria         ###   ########.fr       */
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
	int				chksize;
	int				cost;
	long			*arr;
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
char	ft_validarg(char *s);
long	*create_ltab(int ac, char **av);
int		ft_find_index(long *tab, int size, int nbr);

int		ft_sqrt_floor(int nb);

/*  Stack Related Functions  */
// void	ft_stack_addfront(t_stack **stack, t_stack *new_nd);
t_stack	*create_stack_a(int ac, char **av, long *arr, t_chunk chunki);
t_stack	*ft_stack_newnode(long *arr, int value, int index, int chunk_size);
t_stack	*ft_stacklast(t_stack *lst);
void	ft_stack_clear(t_stack *lst);
t_chunk	ft_chunkinit(int stack_size);
char	check_sort(t_stack *s, int asc);
int		ft_stack_size(t_stack *top);
t_stack	*ft_stack_middle(t_stack *start);
t_stack	*node_search(t_stack *s, int nb);
t_stack	*find_highest(t_stack *a);
t_stack	*find_nexthighest(t_stack *s, t_stack *ref);
t_stack	*find_lowest(t_stack *b);
t_stack	*find_nextlowest(t_stack *s, t_stack *ref);

/*  Movement Functions  */
// which_stack: 0 -> A; 1 -> B; 2 -> both; -1 -> prints nothing
void	stack_swap(t_stack **top, int which_stack);
void	stack_ss(t_stack **topa, t_stack **topb);
void	stack_push(t_stack **topa, t_stack **topb, int which_stack);
void	stack_rotate(t_stack **top,int which_stack);
void	stack_rr(t_stack **topa, t_stack **topb);
void	stack_revrotate(t_stack **top, int which_stack);
void	stack_rrr(t_stack **topa, t_stack **topb);

/*  Operation Functions  */
char	chunk_search(t_stack *a, int chunk);
void	chunk_getcost(t_stack **top, t_stack **bot, int chunk);
void	chunk_prep(t_stack **a, t_stack **b, int chunk);
void	chunk_sendtop(t_stack **a, t_stack **b, t_stack **top, t_stack **bot);
void	sort_three_a(t_stack **a);
void	sort_three_b(t_stack **b);
void	sort_five_a(t_stack **a, t_stack **b);
void	sort_five_b(t_stack **a, t_stack **b);
int		get_node_cost(t_stack *top, t_stack **target);
void	big_sort(t_stack **b, t_stack **a, t_stack *target, int rota);

void	handle_stack(char **nav, t_chunk chunki, long *arr, int size);
void	handle_small_sort(t_stack *a, int size);
void	handle_big_sort(t_stack *a, int size);

#endif
