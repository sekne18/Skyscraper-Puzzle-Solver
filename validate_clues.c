/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_clues.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneves-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:27:28 by gneves-o          #+#    #+#             */
/*   Updated: 2024/09/15 15:33:40 by jsekne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	get_size(int *array);

int	validate_row_left(int row, int col, int **array, int **clues)
{
	int	i;
	int	j;
	int	size;
	int	count;

	size = get_size(clues[0]);
	count = 1;
	i = 0;
	j = i + 1;
	while (j <= col)
	{
		if (array[row][i] < array[row][j])
		{
			i = j;
			count++;
		}
		j++;
		if (count > clues[2][row])
			return (0);
	}
	if (j == size && count != clues[2][row])
		return (0);
	return (1);
}

int	validate_row_right(int row, int **array, int **clues)
{
	int	i;
	int	j;
	int	size;
	int	count;

	size = get_size(clues[0]);
	count = 1;
	i = size - 1;
	j = i - 1;
	while (j >= 0)
	{
		if (array[row][i] < array[row][j])
		{
			i = j;
			count++;
		}
		j--;
		if (count > clues[3][row])
			return (0);
	}
	if (j == -1 && count != clues[3][row])
		return (0);
	return (1);
}

int	validate_col_top(int row, int col, int **array, int **clues)
{
	int	i;
	int	j;
	int	size;
	int	count;

	size = get_size(clues[0]);
	count = 1;
	i = 0;
	j = 1;
	while (j <= row)
	{
		if (array[i][col] < array[j][col])
		{
			i = j;
			count++;
		}
		j++;
		if (count > clues[0][col])
			return (0);
	}
	if (j == size && count != clues[0][col])
		return (0);
	return (1);
}

int	validate_col_bottom(int col, int **array, int **clues)
{
	int	i;
	int	j;
	int	size;
	int	count;

	size = get_size(clues[0]);
	count = 1;
	i = size - 1;
	j = i - 1;
	while (j >= 0)
	{
		if (array[i][col] < array[j][col])
		{
			i = j;
			count++;
		}
		j--;
		if (count > clues[1][col])
			return (0);
	}
	if (j == -1 && count != clues[1][col])
		return (0);
	return (1);
}
