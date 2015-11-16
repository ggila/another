/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   another.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 01:40:49 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/16 23:32:29 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANOTHER_H
# define ANOTHER_H

# include "SFML/Graphics.hpp"
# include <cmath>
# include <ctime>
# include <list>
# include <iostream>

# include "geometrie.hpp"

# define WIDTH 800
# define HEIGHT 800

# define X 0
# define Y 1

# define PIETONRAD 4
# define PIETONSPEED 6

# define MAXFOULESIZE 300

# define MAXSTRESS 75
# define STRESSRAD (30 * PIETONRAD)

class		Foule;
class		Pieton;

#endif
