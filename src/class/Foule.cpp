/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Foule.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 02:09:03 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/15 03:58:33 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "another.h"
#include "Foule.hpp"

void	Foule::newPieton(void)
{
	size_t	i = 0;

	while (i < MAXFOULESIZE && this->_foule[i].isAlive())
		i++;
	if (i == MAXFOULESIZE)
		return;
	this->_foule[i].born();
}

void	Foule::draw(sf::RenderWindow &app)
{
	for(size_t	i = 0; i < MAXFOULESIZE; ++i)
		if (this->_foule[i].isAlive())
			app.draw(this->_foule[i].getImg());
}

void	Foule::move(void)
{
	for(size_t	i = 0; i < MAXFOULESIZE; ++i)
		if (this->_foule[i].isAlive())
			this->_foule[i].move(this->_foule);
}
