/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pieton.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 02:45:17 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/14 06:59:10 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "another.h"
# include "Pieton.hpp"

Pieton::Pieton(void): _speed(5)
{
	bool	t1 = rand() % 2;
	bool	t2 = rand() % 2;
	int		ang = rand();

	if (t1)
	{
		this->_pos[X] = rand() % WIDTH;
		this->_pos[Y] = t2 ? 0 : HEIGHT;
		this->_dir[X] = cos(ang);
		this->_dir[Y] = t2 ? std::abs(sin(ang)) : -std::abs(sin(ang));
	}
	else
	{
		this->_pos[X] = t2 ? 0 : WIDTH;
		this->_pos[Y] = rand() % HEIGHT;
		this->_dir[X] = t2 ? std::abs(sin(ang)) : -std::abs(sin(ang));
		this->_dir[Y] = cos(ang);
	}
	this->_img.setRadius(5);
	this->_img.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255, 255));
}

void	Pieton::move(void)
{
	this->_pos[X] += this->_dir[X] * this->_speed;
	this->_pos[Y] += this->_dir[Y] * this->_speed;
	this->_img.setPosition(sf::Vector2f(this->_pos[X], this->_pos[Y]));
}

bool			Pieton::out(void)
{
	if (this->_pos[X] < 0 || this->_pos[X] > WIDTH ||
			this->_pos[Y] < 0 || this->_pos[Y] > HEIGHT)
		return true;
	return false;
}
