/**
 * @file graphy.h
 *
 * @authors MrColour FlavorlessQuark
 *
 * @version 1.0
 *
 * @brief This library was created to. It contains function to create graphs
 * and points to be displayed on a graph as well as point rescaling functions
 * as well as graph and points template display functions.
 * The points shall be displayed as circles and the graph as a grid whose
 * bottom left corner shall act as its origin (defined from GRAPH_X_ORIGIN and
 * GRAPH_Y_ORIGIN)
 */

#ifndef GRAPHY_H
# define GRAPHY_H

#  if defined(__cplusplus)
extern "C" {
# endif /* C++ compatibility */

# include <stdbool.h>
# include <stdlib.h>

# define GRAPH_WIDTH (500)
# define GRAPH_HEIGHT (500)

# define GRAPH_X_ORIGIN (100)
# define GRAPH_Y_ORIGIN (600)

# define GRAPH_DIV_HEIGHT (100)
# define GRAPH_DIV_WIDTH (600)

/** @brief x and y coordinates  */
typedef struct	s_coordinates
{
	int			x;
	int			y;
}				t_coordinates;

/**
 * @brief Strucure to render a graph
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

/** @brief Point on the graph
 ** @param coord graph space coordinates
 ** @param active whether or not to render the point
 ** @param size size of the point to be rendered
 ** @param color color to be displayed
 ** @param data additional data
*/
typedef struct	s_point
{
	t_coordinates coord;

	bool		active;

	int			size;
	int			color;

	void		*data;
}				t_point;

/**
 * @brief Intializes a t_graph from given parameters and GRAPH_WIDTH/HEIGHT | GRAPH_X/Y_ORIGIN macros
 * @param x_min|x_max Graph space maximum and minimum displayable x values
 * @param y_min|y_max Graph space maximum and minimum displayable y values
*/
t_graph	init_graph(int x_min, int x_max, int y_min, int y_max)

/**
 * @brief Fills *DEST with SIZE t_point initialized from FUNC
 * @param dest array to be initialized
 * @param size size of DEST
 * @param data data that will be used to fill DEST
 * @param width value in byes by which to increment DATA
 * @param func function which shall be passed DATA and whose return value shall be used to initialize each member of DEST
*/
void			points_create(t_point *dest, int size, void *data, int width, t_point (*func)(void *));

/** @brief Adjusts the coordinates of AMOUNT t_points from *POINTS  according to the return value of FUNC*/
void			points_adjust(t_point *points, t_graph graph, int amount, t_coordinates (*func)(t_coordinates, t_graph));

/* Translates graph space coordinates to screenspace coordinates*/
t_coordinates	coord_GraphToScreen(t_coordinates coord, t_graph graph);
/* Translates graph screen coordinates to graph space coordinates*/
t_coordinates	coord_ScreenToGraph(t_coordinates coord, t_graph graph);

bool			in_point(int x, int y, t_point point);
void			out_circle(t_point circle, void (*f)(void *, int, int), void *meta_data);
t_point			get_average(t_point *point_arr, int size);


#  if defined(__cplusplus)
}
# endif  /* End C++ compatibility */

#endif /* End Header */
