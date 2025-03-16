/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array_util.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsekne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 17:45:47 by jsekne            #+#    #+#             */
/*   Updated: 2024/09/15 17:53:32 by jsekne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	**create_array(int size, int type)
{
	int	**array;
	int	i;

	i = -1;
	if (type == 1)
	{
		array = malloc((size + 1) * sizeof(int *));
		while (++i < size + 1)
			array[i] = malloc((size + 1) * sizeof(int));
	}
	else
	{
		array = malloc(size * sizeof(int *));
		while (++i < size)
			array[i] = malloc(size * sizeof(int));
	}
	return (array);
}

void	free_array(int **array, int **clues, int size)
{
	int	i;

	i = -1;
	while (++i < size)
		free(array[i]);
	i = -1;
	while (++i < size + 1)
		free(clues[i]);
	free(array);
	free(clues);
}

void	fill_clues(int **clues, int *input, int size)
{
	int	x;
	int	y;
	int	c;

	y = -1;
	c = 0;
	while (++y < size)
	{
		x = -1;
		while (++x < size + 1)
		{
			if (x == size)
				clues[y][x] = 0;
			else
				clues[y][x] = input[c++];
		}
	}
}
