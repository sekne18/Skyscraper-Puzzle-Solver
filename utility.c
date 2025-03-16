/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utility.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jsekne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/15 10:29:16 by jsekne            #+#    #+#             */
/*   Updated: 2024/09/15 17:35:25 by jsekne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>
#include <unistd.h>

int	*parse_numbers(char *str, int *len, int *highest_num, int *array);

int	*format_argument(char *str, int *size)
{
	int	len;
	int	*array;
	int	highest_num;

	array = malloc(36 * sizeof(int));
	if (!parse_numbers(str, &len, &highest_num, array))
	{
		free(array);
		return (NULL);
	}
	if (len % 4 != 0 || highest_num > (len / 4))
	{
		free(array);
		return (NULL);
	}
	*size = len / 4;
	return (array);
}

int	*parse_numbers(char *str, int *len, int *highest_num, int *array)
{
	*len = 0;
	*highest_num = 0;
	while (*str && *len <= 36)
	{
		if (*str >= '0' && *str <= '9')
		{
			array[*len] = ((int)*str - '0');
			if (array[*len] > *highest_num)
				*highest_num = array[*len];
			(*len)++;
		}
		else if (*str != ' ')
			return (NULL);
		str++;
	}
	return (array);
}

void	print_error_msg(void)
{
	write(1, "Invalid input.\n**Make sure your input was correct**\n", 53);
}

int	get_size(int *array)
{
	int	size;

	size = 0;
	while (array[size] != 0)
		size++;
	return (size);
}
