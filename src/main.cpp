/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 23:44:52 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/15 05:20:26 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "another.h"
#include "class/Foule.hpp"

#include<iostream>
int	main(void)
{
	srand(time(NULL));
	sf::RenderWindow	app(sf::VideoMode(WIDTH, HEIGHT, 32), "another",
			sf::Style::Close);

	Foule	crowd;
	bool	pause;

	while (app.isOpen())
	{
		sf::Event	e;

		while (app.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				app.close();
			if (e.type == sf::Event::KeyPressed)
				pause = !pause;
		}

		crowd.newPieton();

		if (!pause)
		{
			app.clear();
			crowd.move();
			crowd.draw(app);
			app.display();

			if (!(rand() % 10))
				std::cout << "On map: " << Pieton::population <<std::endl;
		}

		usleep(30000);
	}
	return 0;
}
