#include <math.h>
#include <stdio.h>
#include <stdlib.h>

	// unsigned int	n;
	//
	// n = 1;
	// if (nb <= 0)
	// 	return (0);
	// while (n * n < (unsigned int)nb)
	// 	n++;
	// if (n * n == (unsigned int)nb)
	// 	return (n);
	// return (0)

// double	ft_sqrt(int nb)
// {
//     double  sq;
//
//     // sq = (double)nb;
//     sq = 1;
//     if (nb < 4)
//     {
//         while ((sq * sq) < nb)
//             sq++;
// 	return (sq);
//     }
//     sq = (double)nb / 2;
//     for (int i = 
// 	if (sq * sq == nb)
// 	    return (sq);
// 	else
// 	    return (ft_sqrt(sq));
// }
int ft_sqrt_binary(int nb)
{
    int low;
    int high;
    int mid;
    int result;

    if (nb <= 0)
        return (0);
    if (nb == 1)
        return (1);
    low = 1;
    high = nb / 2;  // For nb >= 4, sqrt(nb) <= nb/2
    result = 0;
    
    while (low <= high)
    {
        mid = low + (high - low) / 2;  // Avoid overflow
        
        if (mid * mid == nb)
            return (mid);  // Perfect square
        else if (mid * mid < nb)
        {
            result = mid;  // Store the largest valid answer
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return (result);
}
// Calculate chunk size using floor of square root
int calculate_chunk_size(int stack_size)
{
    return (int)floor(sqrt(stack_size));
}

// Calculate total number of chunks needed
int calculate_chunk_count(int stack_size, int chunk_size)
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
    if (chunk_number == calculate_chunk_count(stack_size, chunk_size) - 1){
        chunk_end = stack_size - 1;}
	printf("\nchunk_start = %d, chunk_end = %d\n", chunk_start, chunk_end);
    
    return (index >= chunk_start && index <= chunk_end);
}

// Example usage
int main(int ac, char **av)
{
    (void)ac;
    int stack_size = atoi(av[1]);
    int chunk_size = calculate_chunk_size(stack_size);
    int chunk_count = calculate_chunk_count(stack_size, chunk_size);

    printf("Stack size: %d\n", stack_size);
    printf("Stack size squared: %d\n", ft_sqrt_binary(stack_size));
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
