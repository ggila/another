/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pieton.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 02:45:17 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/16 21:46:38 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "another.h"
# include "Pieton.hpp"

int		Pieton::population = 0;

sf::CircleShape	Pieton::getImg(void) {return this->_img;};
bool				Pieton::isAlive(void) {return this->_alive;}
int					Pieton::getX(void) {return this->_pos[X];}
int					Pieton::getY(void) {return this->_pos[Y];}

void	Pieton::born(void)
{
	int		rand_val = rand();
	bool	t1 = rand_val & 0x1;
	bool	t2 = rand_val & (0x1 << 1);

	Pieton::population += 1;
	this->_alive = true;
	if (t1)
	{
		this->_pos[X] = rand_val % WIDTH;
		this->_pos[Y] = t2 ? 0 : HEIGHT;
		this->_dir[X] = cos(rand_val);
		this->_dir[Y] = t2 ? std::abs(sin(rand_val)) : -std::abs(sin(rand_val));
	}
	else
	{
		this->_pos[X] = t2 ? 0 : WIDTH;
		this->_pos[Y] = rand_val % HEIGHT;
		this->_dir[X] = t2 ? std::abs(sin(rand_val)) : -std::abs(sin(rand_val));
		this->_dir[Y] = cos(rand_val);
	}
}

void	Pieton::die(void)
{
	this->_alive = false;
	Pieton::population -= 1;
}

Pieton::Pieton(void): _alive(0), _speed(PIETONSPEED)
{
	this->_img.setRadius(PIETONRAD);
	this->_img.setFillColor(sf::Color(255, 255, 255, 255));
	this->_img.setOrigin(PIETONRAD, PIETONRAD);
//	this->_img.setFillColor(sf::Color(rand()%255, rand()%255, rand()%255, 255));
}

void	Pieton::move(Pieton crowd[])
{
	for (size_t i=0; i<MAXFOULESIZE; ++i)
	{
		if (crowd[i]._alive && this->_collide(crowd[i]))
		{
			this->die();
			crowd[i].die();
			return;
		}
	}
	this->_pos[X] += this->_dir[X] * this->_speed;
	this->_pos[Y] += this->_dir[Y] * this->_speed;
	if (this->out())
		this->die();
	else
		this->_img.setPosition(sf::Vector2f(this->_pos[X], this->_pos[Y]));
}

bool	Pieton::_collide(Pieton &that)
{
	if (this == &that)
		return false;

	int	dist = Geo::norm2nonsqrt(this->_pos, that._pos);
	int	min_dist = pow(2 * PIETONRAD, 2);

	if (dist <= min_dist)
	{
//		std::cout << "COLLISION" <<std::endl;
		return (true);
	}

//	if (dist > 3 * min_dist)
//		return false;

	return (false);
}

bool			Pieton::out(void)
{
	if (this->_pos[X] < 0 || this->_pos[X] > WIDTH ||
			this->_pos[Y] < 0 || this->_pos[Y] > HEIGHT)
		return true;
	return false;
}
