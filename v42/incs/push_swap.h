/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 20:09:11 by manmaria          #+#    #+#             */
/*   Updated: 2025/09/12 07:01:56 by manmaria         ###   ########.fr       */
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
	int				cost;
	int				mov;
	struct s_stack	*target;
	struct s_stack	*next;
}					t_stack;

/*  Array Related Functions  */
int		find_index(long *tab, int size, int nbr);
int		ft_sort_ltab(long *tab, int size);
char	ft_validarg(char *s);
long	*create_ltab(int ac, char **av, char flag);

/*  Stack Related Functions  */
t_stack	*create_stack_a(int ac, char **av, long *arr);
t_stack	*stack_newnode(int value, int index);
t_stack	*ft_stacklast(t_stack *lst);
int		ft_stack_size(t_stack *top);
char	check_sort(t_stack *s, int asc);
void	ft_stack_clear(t_stack *lst);
// Search functions
t_stack	*node_search(t_stack *s, int nb);
t_stack	*find_highest(t_stack *a);
t_stack	*find_nexthighest(t_stack *s, t_stack *ref);
t_stack	*find_lowest(t_stack *b);
t_stack	*find_nextlowest(t_stack *s, t_stack *ref);

/*  Movement Functions  */
void	stack_swap(t_stack **top, int which_stack);
void	stack_ss(t_stack **topa, t_stack **topb);
void	stack_push(t_stack **topa, t_stack **topb, int which_stack);
void	stack_rotate(t_stack **top, int which_stack);
void	stack_rr(t_stack **topa, t_stack **topb);
void	stack_revrotate(t_stack **top, int which_stack);
void	stack_rrr(t_stack **topa, t_stack **topb);

/*  Sort Operations Functions  */
t_stack	*get_lesscost(t_stack *s);
void	sort_three_a(t_stack **a);
void	sort_three_b(t_stack **b);
void	sort_five_a(t_stack **a, t_stack **b);
void	sort_five_b(t_stack **a, t_stack **b);
void	double_rotations(t_stack **a, t_stack **b, t_stack *targ);
void	single_rotations(t_stack **a, t_stack **b, t_stack *targa, char w);
void	targets_to_top(t_stack **a, t_stack **b);
void	set_target(t_stack *a, t_stack *b, char w);
void	set_mov(t_stack *s);
void	targets_to_top(t_stack **a, t_stack **b);
void	nodes_to_a(t_stack **a, t_stack **b);
int		ft_max(int a, int b);
int		ft_abs(int nb);

/*  Handle Functions  */
void	handle_stack(char **nav, long *arr, int size, char f);
void	handle_small_sort(t_stack **a, int size);
void	handle_big_sort(t_stack **a);
int		handle_free(t_stack **a, long *tab, char **nav, char f);
int		write_error(t_stack **a, long *tab, char **nav, char f);

#endif
