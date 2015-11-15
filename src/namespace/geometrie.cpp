/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometrie.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 16:10:18 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/15 16:45:11 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "geometrie.hpp"

namespace	Geo {
	int	norm1(int vect1[2], int vect2[2])
	{
		int	diffX = std::abs(vect1[X] - vect2[X]);
		int	diffY = std::abs(vect1[Y] - vect2[Y]);

		return diffX > diffY ? diffX : diffY;
	}

	int	norm2nonsqrt(int vect1[2], int vect2[2])
	{
		return std::pow(vect1[X] - vect2[X], 2)
			+ std::pow(vect1[Y] - vect2[Y], 2);
	}

	int	norm2(int vect1[2], int vect2[2])
	{
		return pow(std::pow(vect1[X] - vect2[X], 2)
			+ std::pow(vect1[Y] - vect2[Y], 2), 1/2);
	}
};
