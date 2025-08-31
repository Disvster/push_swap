/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/23 17:09:04 by manmaria          #+#    #+#             */
/*   Updated: 2025/08/27 16:57:47 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../incs/push_swap.h"

t_stack	*ft_create_stack_a(int ac, char **av, long *arr, t_chunk chunki)
{
	int			size;
	int			nbr;
	int			node_id;
	t_stack		*new_nd;
	t_stack		*temp;

	size = ac;
	temp = NULL;
	new_nd = NULL;
	while (--size > 0)
	{
		nbr = ft_atoi(av[size]);
		node_id = ft_find_index(arr, ac - 1, nbr);
		temp = ft_stack_newnode(nbr, node_id, chunki.size);
		if (!temp || node_id == -1)
			return (NULL);
		if (new_nd)
			temp->next = new_nd;
		new_nd = temp;
	}
	return (new_nd);
}
// above I'm creating the stack A in reverse and adding each new node;
// so for 4 Arguments: 1st-node3 -> size-- -> 2nd-node2 -> size-- -> 3rd-node1

t_stack	*ft_stack_newnode(int value, int index, int chunk_size)
{
	t_stack	*new_node;

	new_node = (t_stack *)malloc(sizeof(t_stack));
	if (!new_node)
		return (NULL);
	new_node->value = value;
	new_node->index = index;
	new_node->chunkid = index / chunk_size;
	new_node->next = NULL;
	return (new_node);
}

// NOTE: not using func below atm
//
// void	ft_stack_addfront(t_stack **stack, t_stack *new_nd)
// {
// 	new_nd->next = *stack;
// 	*stack = new_nd;
// }

void	ft_stack_clear(t_stack *lst)
{
	t_stack	*tmp;
	t_stack	*node;

	if (!lst)
		return ;
	node = lst;
	while (node)
	{
		tmp = node->next;
		free(node);
		node = tmp;
	}
	lst = NULL;
}

t_stack	*ft_stacklast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = lst;
	if (!lst)
		return (NULL);
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

// NOTE:
// if (asc == 1) // check for ascending order
// else if (asc == 0) // check for descending order
char	ft_checksort(t_stack *s, int asc, int range)
{
	t_stack	*tmp;
	int		i;

	tmp = s;
	i = -1;
	if (asc == 1 && s)
	{
		while (++i < range && tmp->next)
		{
			if (tmp->index > tmp->next->index)
				return (0);
			tmp = tmp->next;
		}
	}
	else if (asc == 0 && s)
	{
		while (++i < range && tmp->next)
		{
			if (tmp->index < tmp->next->index)
				return (0);
			tmp = tmp->next;
		}
	}
	return (1);
}

int	ft_stack_size(t_stack *top)
{
	int		size;
	t_stack	*tmp;

	if (!top)
		return (0);
	size = 0;
	tmp = top;
	if (!tmp)
		return (0);
	while (tmp)
	{
		tmp = tmp->next;
		size++;
	}
	return (size);
}

t_stack	*ft_stack_middle(t_stack *start)
{
	int		mid;
	int		size;
	int		i;
	t_stack	*tmp;

	if (!start)
		return (NULL);
	mid = ft_stack_size(start) / 2;
	size = ft_stack_size(start);
	i = 0;
	tmp = start;
	if (size % 2 == 0)
		mid -= 1;
	while (i <= mid)
	{
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}
