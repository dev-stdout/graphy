/**
 * @file graphy.h
 *
 * @authors MrColour
 *
 * @version 1.0
 *
 * @brief This file contains the code necessary to display points as circles
 */
#include "graphy.h"

static int	square_distance(int x, int y, int to_x, int to_y)
{
	int	result;
	int	d_x;
	int	d_y;

	d_x = (to_x - x);
	d_y = (to_y - y);
	result = d_x * d_x + d_y * d_y;

	return (result);
}

static void	mirror_valid_cir_point(t_point circle, void *meta_data, t_coordinates at, void (*f)(void *, int, int))
{
	f(meta_data, circle.coord.x + at.x - 1, circle.coord.y + at.y);
	f(meta_data, circle.coord.x + at.x - 1, circle.coord.y - at.y);
	f(meta_data, circle.coord.x - at.x, circle.coord.y + at.y);
	f(meta_data, circle.coord.x - at.x, circle.coord.y - at.y);
}

/**
** @brief This function shall send to function f the points to create a circle.
** @param circle The data of the circle, the position, and radius.
** @param f The function which will be called, it will be passed meta_data if necessary,
** and two `int`s that are on the circle's circumference.
** @param meta_data a void pointer that will be passed to function f for external information.
** If not necessary NULL can be passed into meta_data.
**/
void	out_circle(t_point circle, void (*f)(void *, int, int), void *meta_data)
{
	t_coordinates at;
	int	sq_radius;

	at.x = 0;
	at.y = -(circle.size);
	sq_radius = circle.size;
	sq_radius = sq_radius * sq_radius;
	while (at.x <= circle.size)
	{
		if (square_distance(at.x, at.y, 0, 0) > sq_radius)
			at.y++;
		else
			at.x++;
		mirror_valid_cir_point(circle, meta_data, at, f);
	}
}
