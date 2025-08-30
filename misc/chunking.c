/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: manmaria <manmaria@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 19:09:01 by manmaria          #+#    #+#             */
/*   Updated: 2025/08/22 20:02:29 by manmaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "../incs/push_swap.h"


int ft_sqrt_floor(int nb)
{
    int low;
    int high;
    int mid;
    int result;

    if (nb <= 1)
        return (nb == 1); // returns 0 if condition is false
    low = 1;
    high = nb / 2;
    result = 0;
    while (low <= high)
    {
        mid = low + (high - low) / 2;
        if (mid * mid == nb)
            return (mid);
        else if (mid * mid < nb)
        {
            result = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return (result);
}

// Calculate chunk size using floor of square root
int calc_chunk_size(int stack_size)
{
    return (ft_sqrt_floor(stack_size));
}

// Calculate total number of chunks needed
int calc_chunk_count(int stack_size, int chunk_size)
{
    return (stack_size + chunk_size - 1) / chunk_size;  // Ceiling division
}

// Determine which chunk an index belongs to
int get_chunk_number(int index, int chunk_size)
{
    return index / chunk_size;
}

// Check if an index belongs to a specific chunk
int is_in_chunk(int index, int chunk_number, int chunk_size, int stack_size)
{
    int chunk_start = chunk_number * chunk_size;
    int chunk_end = chunk_start + chunk_size - 1;
    
    // Handle the last chunk which might be larger
    if (chunk_number == calc_chunk_count(stack_size, chunk_size) - 1){
        chunk_end = stack_size - 1;}
	printf("\nchunk_start = %d, chunk_end = %d\n", chunk_start, chunk_end);
    
    return (index >= chunk_start && index <= chunk_end);
}

t_chunk    ft_schunkinit(int stack_size)
{
    t_chunk	chunki;

    chunki.size = calc_chunk_size(stack_size);
    chunki.count = calc_chunk_count(stack_size, chunki.size);
    printf("Stack size: %d\n", stack_size);
    printf("Stack size squared: %d\n", ft_sqrt_floor(stack_size));
    printf("Chunk size: %d\n", chunki.size);
    printf("Number of chunks: %d\n", chunki.count);
    return (chunki);
}

t_chunk	ft_chunkinit(int stack_size)
{
	t_chunk	chunki;

	chunki.size = calc_chunk_size(stack_size);
	chunki.count = calc_chunk_count(stack_size, chunki.size);
	return (chunki);
}

// Example usage
int main(int ac, char **av)
{
    (void)ac;
    int stack_size = atoi(av[1]);
    int chunk_size = calc_chunk_size(stack_size);
    int chunk_count = calc_chunk_count(stack_size, chunk_size);

    printf("Stack size: %d\n", stack_size);
    printf("Stack size squared: %d\n", ft_sqrt_floor(stack_size));
    printf("Chunk size: %d\n", chunk_size);
    printf("Number of chunks: %d\n", chunk_count);

    // Show chunk distribution
    int i = 0;
    while (i < chunk_count)
    {
	int start = i * chunk_size;
	int end;
	
	if (i == chunk_count - 1)
	    end = stack_size - 1;
	else
	    end = start + chunk_size - 1;
	
	printf("Chunk %d: indices %d to %d (%d elements)\n", 
	       i, start, end, end - start + 1);
	i++;
    }
    
    return 0;
}
