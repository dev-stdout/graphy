/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   graphy_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: home <home@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 05:09:53 by home              #+#    #+#             */
/*   Updated: 2020/10/31 05:10:01 by home             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "graphy.h"

t_graph	init_graph(int x_min, int x_max, int y_min, int y_max)
{
	t_graph graph;

	graph.height = GRAPH_HEIGHT;
	graph.width  = GRAPH_WIDTH;

	graph.origin_x = GRAPH_X_ORIGIN;
	graph.origin_y = GRAPH_Y_ORIGIN;

	graph.div_height = 10;
	graph.div_width  = 10;

	graph.x_max = x_max;
	graph.x_min = x_min;

	graph.y_max = y_max;
	graph.y_min = y_min;

	return (graph);
}
