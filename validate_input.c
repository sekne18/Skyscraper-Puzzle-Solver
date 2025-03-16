/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gneves-o <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/14 11:27:28 by gneves-o          #+#    #+#             */
/*   Updated: 2024/09/15 15:33:09 by jsekne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	validate_row_left(int row, int col, int **array, int **clues);
int	validate_row_right(int row, int **array, int **clues);
int	validate_col_top(int row, int col, int **array, int **clues);
int	validate_col_bottom(int col, int **array, int **clues);
int	is_unique(int row, int col, int num, int **array);
int	get_size(int *array);

int	validate_input(int row, int col, int **array, int **clues)
{
	int	num;
	int	size;

	num = array[row][col];
	size = get_size(clues[0]);
	if (!is_unique(row, col, num, array))
		return (0);
	if (!validate_row_left(row, col, array, clues))
		return (0);
	if (col == size - 1 && !validate_row_right(row, array, clues))
		return (0);
	if (!validate_col_top(row, col, array, clues))
		return (0);
	if (row == size - 1 && !validate_col_bottom(col, array, clues))
		return (0);
	return (1);
}

int	is_unique(int row, int col, int num, int **array)
{
	int	i;

	i = 0;
	while (i < col)
		if (array[row][i++] == num)
			return (0);
	i = 0;
	while (i < row)
		if (array[i++][col] == num)
			return (0);
	return (1);
}
