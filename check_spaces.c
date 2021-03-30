/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_spaces.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abrun <abrun@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 11:48:42 by abrun             #+#    #+#             */
/*   Updated: 2021/03/30 12:22:18 by abrun            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../game.h"

int			check_spaces(char **map, int height)
{
	int		i;
	int		j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 32)
				if (is_one_around(map, i, j, height))
				{
					printf("Il y a un espace dans la map !\n");
					return (0);
				}
			j++;
		}
		i++;
	}
	return (1);
}

int			is_one_around(char **map, int i, int j, int height)
{
	if (check_right_left(map, i, j) && check_up_down(map, i, j, height))
		return (1);
	return (0);
}

int			check_up_down(char **map, int i, int j, int height)
{
	int		k;
	int		up;

	k = i;
	up = 0;
	while (i-- > -1 && !up)
	{
		if (map[i][j] == '1')
			up = 1;
	}
	if (!up)
		return (0);
	while (k++ < height)
	{
		if (map[k][j] == '1')
			return (1);
	}
	return (0);
}
int			check_right_left(char **map, int i, int j)
{
	int		k;
	int		left;

	k = j;
	left = 0;
	while (j-- > -1 && !left)
	{
		if (map[i][j] == '1')
			left = 1;
	}
	if (!left)
		return (0);
	while (map[i][k++])
	{
		if (map[i][k] == '1')
			return (1);
	}
	return (0);
}
