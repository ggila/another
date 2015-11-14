/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 23:44:52 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/14 07:05:18 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "another.h"
#include "class/Pieton.hpp"

#include<iostream>
int	main(void)
{
	srand(time(NULL));
	sf::RenderWindow	app(sf::VideoMode(WIDTH, HEIGHT, 32), "another",
			sf::Style::Close);

	std::list<Pieton>	foule;

	while (app.isOpen())
	{
		sf::Event	e;

		while (app.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				app.close();
		}

		if (!(rand() % 2))
			foule.push_back(Pieton());

		app.clear();
		std::list<Pieton>::iterator it = foule.begin();
		while (it != foule.end())
		{
			it->move();
			if (it->out())
				it = foule.erase(it);
			else
			{
				app.draw(*it);
				it++;
			}
		}
		app.display();

		usleep(3000);
	}
	return 0;
}
