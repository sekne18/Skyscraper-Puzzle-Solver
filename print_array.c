/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_array.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsekne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 11:26:50 by jsekne            #+#    #+#             */
/*   Updated: 2024/09/15 15:51:06 by jsekne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>

void	print_error_msg(void);

void	print_separator(int size)
{
	int	i;

	i = 0;
	write(1, "   ", 3);
	while (i++ < size)
		write(1, "+++++", 5);
	write(1, "\b \b\n", 4);
}

void	print_line(int **clues, int size, int clue_index)
{
	int		ci;
	char	tmp;

	ci = 0;
	write(1, "   ", 3);
	while (ci < size)
	{
		write(1, "   ", 3);
		tmp = clues[clue_index][ci++] + '0';
		write(1, &tmp, 1);
	}
	write(1, "\n", 1);
}

void	print_row(int *array[], int **clues, int i, int size)
{
	int		j;
	char	tmp;

	j = 0;
	write(1, " ", 1);
	tmp = clues[2][i] + '0';
	write(1, &tmp, 1);
	write(1, " +  ", 4);
	while (j < size)
	{
		tmp = array[i][j] + '0';
		write(1, &tmp, 1);
		if (j++ < size - 1)
			write(1, " | ", 3);
	}
	write(1, "  + ", 4);
	tmp = clues[3][i] + '0';
	write(1, &tmp, 1);
	write(1, "\n", 1);
}

void	print_array(int *array[], int **clues, int size)
{
	int	i;

	if (array[0][0] == 0)
		write(1, "Error\n", 6);
	else
	{
		i = 0;
		print_line(clues, size, 0);
		print_separator(size);
		while (i < size)
			print_row(array, clues, i++, size);
		print_separator(size);
		print_line(clues, size, 1);
	}
}
