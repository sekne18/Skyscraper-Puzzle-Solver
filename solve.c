/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solve.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsekne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 08:46:34 by jsekne            #+#    #+#             */
/*   Updated: 2024/09/15 19:07:48 by jsekne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdio.h>

int	validate_input(int row, int col, int **array, int **clues);
int	get_size(int *array);

int	solve(int row, int col, int *array[], int *clues[])
{
	int	number;
	int	size;

	size = get_size(clues[0]);
	if (col == size)
	{
		if (row + 1 == size)
			return (1);
		else
			return (solve(row + 1, 0, array, clues));
	}
	number = 0;
	while (++number <= size)
	{
		array[row][col] = number;
		if (validate_input(row, col, array, clues))
		{
			if (solve(row, col + 1, array, clues))
				return (1);
		}
	}
	array[row][col] = 0;
	return (0);
}
