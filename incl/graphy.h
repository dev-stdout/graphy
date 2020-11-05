/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphy.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 03:24:03 by home              #+#    #+#             */
/*   Updated: 2020/10/31 05:10:44 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GRAPHY_H
# define GRAPHY_H

# include <stdbool.h>
# include <stdlib.h>

# include "window_config.h"

# define WIN_X_OFFSET (100)
# define WIN_Y_OFFSET (100)

# define GRAPH_WIDTH (500)
# define GRAPH_HEIGHT (500)

# define GRAPH_X_ORIGIN (100)
# define GRAPH_Y_ORIGIN (600)

typedef struct	s_coordinates
{
	int			x;
	int			y;
}				t_coordinates;

/* Strucure to render a graph
 * @param width ScreenSpace width
 * @param height Screenspace height
 * @param div_width Number of vertical divisions
 * @param div_height Number of Horizontal division
 * @param origin_x Screenspace X coordinate of bottom left corner
 * @param origin_y Screenspace Y coordinate of bottom right corner
 * @param x_min|x_max GraphSpace minimum and maximum X values
 * @param y_min|y_max GraphSpace minimum and maximum Y values*/
typedef struct	s_graph
{
	int			width;
	int			height;

	int			div_width;
	int			div_height;

	int			origin_x;
	int			origin_y;

	int			x_min;
	int			x_max;

	int			y_min;
	int			y_max;

}				t_graph;


typedef struct	s_point
{
	t_coordinates coord;

	bool		active;

	int			size;
	int			color;

	void		*data;
}				t_point;

t_graph	init_graph(void);

/* Fills *DEST with SIZE t_point initialized from FUNC */
void			points_create(t_point *dest, void *data, int size, int width, t_point (*func)(void *));

/* Adjusts the coordinates of AMOUNT t_points from *POINTS  according to the return value of FUNC*/
void			points_adjust(t_point *points, t_graph graph, int amount, t_coordinates (*func)(t_coordinates, t_graph));

/* Translates graph space coordinates to screenspace coordinates*/
t_coordinates	coord_GraphToScreen(t_coordinates coord, t_graph graph);
/* Translates graph screen coordinates to graph space coordinates*/
t_coordinates	coord_ScreenToGraph(t_coordinates coord, t_graph graph);

bool			in_point(int x, int y, t_point point);
void			out_circle(t_point circle, void (*f)(void *, int, int), void *meta_data);
t_point			get_average(t_point *point_arr, int size);

#endif
