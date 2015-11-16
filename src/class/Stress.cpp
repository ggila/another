/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stress.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 15:14:10 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/16 22:50:42 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "another.h"
#include "Stress.hpp"
#include "Pieton.hpp"
#include "Foule.hpp"

Stress	*Stress::_single = NULL;

Stress	*Stress::instance(void)
{
	if (!Stress::_single)
		Stress::_single = new Stress;
	return Stress::_single;
}

Stress::Stress(void)
{
	memset(this->_tab, 0, HEIGHT * WIDTH);

	// set One stress
	char stressFunc[STRESSRAD];
	memset(stressFunc, 0, PIETONRAD);
	for (int i=PIETONRAD; i < STRESSRAD; ++i) 
		stressFunc[i] = MAXSTRESS * std::exp((PIETONRAD - i) * (3. / STRESSRAD));

	memset(this->_oneStress, 0, STRESSRAD * STRESSRAD);
	double inc = std::atan(1./STRESSRAD) / 2;
	for (double theta=0; theta < 2 * M_PI; theta += inc)
	{
		for (int r=PIETONRAD; r<STRESSRAD; ++r)
		{
			int i = r * std::cos(theta);
			int j = r * std::sin(theta);
			this->_oneStress[i + STRESSRAD][j + STRESSRAD] = stressFunc[r];
		}
	}
}

void	Stress::_addPieton(Pieton &P)
{
	int	x = P.getX();
	int	y = P.getY();
	int	minX = x > STRESSRAD ? -STRESSRAD : -x;
	int	maxX = x < WIDTH - STRESSRAD ? STRESSRAD : WIDTH - x;
	int	minY = y > STRESSRAD ? -STRESSRAD : -y;
	int	maxY = y < HEIGHT - STRESSRAD ? STRESSRAD : HEIGHT - y;

	for (int i=minX; i<maxX; ++i) {
		for (int j=minY; j<maxY; ++j){
//			std::cout << i << "," << j  << std::endl;
			this->_tab[y + j][x + i] += this->_oneStress[STRESSRAD + j][STRESSRAD + i];
	}}
}

void	Stress::update(Foule *foule)
{
//	static bool	alt = true;

//	alt = !alt;
//	this->_current = alt ? this->_tab1: this->_tab2;
	memset(this->_tab, 0, HEIGHT * WIDTH);
	for (size_t i=0; i < MAXFOULESIZE; ++i)
	{
		if (foule->_foule[i].isAlive())
			this->_addPieton(foule->_foule[i]);
	}
//	for (int i=750; i<WIDTH; ++i){
//		for (int j=500; j<WIDTH; ++j) {
//			std::cout << this->_tab[j][i] << " ";
//		}
//		std::cout  << std::endl;
//	}
}


void	Stress::draw(sf::RenderWindow &app)
{
	sf::Uint8		*pixels  = new sf::Uint8[WIDTH * HEIGHT * 4];

	sf::Texture		texture;
	texture.create(WIDTH, HEIGHT);

	sf::Sprite		sprite(texture);

	for(int x = 0; x < WIDTH  ; x++)
	{
		for(int y = 0; y < HEIGHT; y++)
		{
			pixels[(WIDTH*y + x) * 4] = this->_tab[y][x]; // R
			pixels[(WIDTH*y + x) * 4 + 1] = 0; // R
			pixels[(WIDTH*y + x) * 4 + 2] = 0; // R
			pixels[(WIDTH*y + x) * 4 + 3] = 255;
		}
	}
	texture.update(pixels);
	app.draw(sprite);

	delete [] pixels;
}
