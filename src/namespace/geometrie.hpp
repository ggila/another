/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   geometrie.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 16:44:31 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/15 16:44:53 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <cmath>
#include <cstdlib>

# define X 0
# define Y 1

namespace	Geo {
	int	norm1(int vect1[2], int vect2[2]);
	int	norm2nonsqrt(int vect1[2], int vect2[2]);
	int	norm2(int vect1[2], int vect2[2]);
};
