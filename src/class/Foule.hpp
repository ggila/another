/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Foule.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 02:04:30 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/15 15:47:26 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOULE_HPP
# define FOULE_HPP

# include "another.h"
#include "Pieton.hpp"

class Foule{
	public:
		void	newPieton(void);
		void	draw(sf::RenderWindow &app);
		void	move(void);

	private:
		Pieton	_foule[MAXFOULESIZE];
};

#endif
