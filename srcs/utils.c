/**
 * @file graphy.h
 *
 * @authors MrColour FlavorlessQuark
 *
 * @version 1.0
 *
 * @brief This file contains various utilities functions
 */

# include "graphy.h"

t_point	get_average(t_point *point_arr, int size)
{
	int		i;
	t_point	result;

	i = 0;
	while (i < size)
	{
		result.coord.x += point_arr[i].coord.x;
		result.coord.y += point_arr[i].coord.y;

		result.size += point_arr[i].size;
		result.color += point_arr[i].color;

		i++;
	}

	result.coord.x /= size;
	result.coord.y /= size;

	result.size /= size;
	result.color /= size;

	result.active = true;
	result.data = NULL;

	return (result);
}

bool	in_point(int x, int y, t_point point)
{
	int	x_dis_squared;
	int	y_dis_squared;

	x_dis_squared = x - point.coord.x;
	y_dis_squared = y - point.coord.y;

	x_dis_squared *= x_dis_squared;
	y_dis_squared *= y_dis_squared;

	if (point.size * point.size > x_dis_squared + y_dis_squared)
		return (true);
	else
		return (false);
}
