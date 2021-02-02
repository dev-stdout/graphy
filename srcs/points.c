/**
 * @file points.c
 *
 * @authors FlavorlessQuark
 *
 * @version 1.0
 *
 * @brief This file contains various scaling functions
 * so that points may be displayed appropriately on a graph
 */

# include "graphy.h"

int			num_Scale(int input, int from_min, int from_max, int to_min, int to_max)
{
	int		result;
	int		range;
	double	tmp;

	range = (from_max - from_min);

	tmp = input - from_min;
	tmp /= range;
	tmp *= (to_max - to_min);
	result = tmp + to_min;

	return result;
}

t_coordinates coord_Scale(t_coordinates input, t_coordinates from_x, t_coordinates from_y,
											   t_coordinates to_x, t_coordinates to_y)
{
	t_coordinates output;

	output.x = num_Scale(input.x, from_x.x, from_x.y, to_x.x, to_x.y);
	output.y = num_Scale(input.y, from_y.x, from_y.y, to_y.x, to_y.y);

	return output;
}

void	points_create(t_point *dest, int size, void *data, int width, t_point (*func)(void *))
{
	int		i;

	i = 0;
	while (i < size)
	{
		dest[i] = func(data);
		data += width;
		i++;
	}
}

void	points_adjust(t_point *points, t_graph graph, int amount,
						t_coordinates (*func)(t_coordinates, t_graph))
{
	int i;

	i = 0;
	while (i < amount)
	{
		points[i].coord = func(points[i].coord, graph);
		i++;
	}
}

t_coordinates	coord_GraphToScreen(t_coordinates coord, t_graph graph)
{
	t_coordinates	screen_coord;
	int				y_range;
	int				x_range;
	double			x_tmp;
	double			y_tmp;

	x_range = (graph.x_max - graph.x_min);
	y_range = (graph.y_max - graph.y_min);

	x_tmp = coord.x - graph.x_min;
	y_tmp = coord.y - graph.y_min;

	x_tmp /= x_range;
	y_tmp /= y_range;

	x_tmp *= (graph.width);
	y_tmp *= (graph.height) * -1;

	screen_coord.x = x_tmp + graph.origin_x;
	screen_coord.y = y_tmp + graph.origin_y;

	return screen_coord;
}

t_coordinates	coord_ScreenToGraph(t_coordinates coord,  t_graph graph)
{
	t_coordinates	graph_coord;
	int				y_range;
	int				x_range;
	double			x_tmp;
	double			y_tmp;

	x_range = (graph.width);
	y_range = (graph.height);

	x_tmp = coord.x - graph.origin_x;
	y_tmp = coord.y - graph.origin_y;

	x_tmp /= x_range;
	y_tmp /= y_range;

	x_tmp *= (graph.x_max - graph.x_min);
	y_tmp *= (graph.y_max - graph.y_min) * - 1;

	graph_coord.x = x_tmp + graph.x_min;
	graph_coord.y = y_tmp + graph.y_min;

	return graph_coord;
}

