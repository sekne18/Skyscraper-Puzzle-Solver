/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsekne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:31:18 by jsekne            #+#    #+#             */
/*   Updated: 2024/09/15 19:06:21 by jsekne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

void	print_error_msg(void);
void	print_array(int *array[], int **clues, int size);
void	fill_clues(int **clues, int *input, int size);
int		*format_argument(char *str, int *size);
int		**create_array(int size, int type);
int		solve(int row, int col, int **array, int **clues);
void	free_array(int **array, int **clues, int size);

void	rush01(char *str)
{
	int	**array;
	int	**clues;
	int	size;
	int	*input_clues;

	input_clues = format_argument(str, &size);
	if (input_clues == NULL)
	{
		print_error_msg();
		return ;
	}
	array = create_array(size, 0);
	clues = create_array(size, 1);
	fill_clues(clues, input_clues, size);
	solve(0, 0, array, clues);
	print_array(array, clues, size);
	free(input_clues);
	free_array(array, clues, size);
}
