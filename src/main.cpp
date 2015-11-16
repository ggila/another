/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/13 23:44:52 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/16 23:26:49 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "another.h"
#include "Foule.hpp"
#include "Pieton.hpp"
#include "Stress.hpp"

/*
int main(void)
{
	Stress	*stress = Stress::instance();
	stress->fff();
	return (0);
}
*/

int	main(void)
{
	srand(time(NULL));
	sf::RenderWindow	app(sf::VideoMode(WIDTH, HEIGHT, 32), "another",
			sf::Style::Close);

	bool	pause;
	bool	drawStress = false;
	bool	drawPieton = false;

	Foule	*crowd = Foule::instance();
	Stress	*stress = Stress::instance();

	while (app.isOpen())
	{
		sf::Event	e;

		while (app.pollEvent(e))
		{
			if (e.type == sf::Event::Closed)
				app.close();
			if (e.text.unicode == ' ')
				pause = !pause;
			if (e.text.unicode == 's')
				drawStress = !drawStress;
			if (e.text.unicode == 'p')
				drawPieton = !drawPieton;
		}

		if (!pause)
		{
			if (rand()%10)
				crowd->newPieton();

			app.clear();
			crowd->move();
			stress->update(crowd);
//	std::cout << "blabla" << std::endl;
			if (drawStress)
				stress->draw(app);
//	std::cout << "blabla" << std::endl;
			if (drawPieton)
				crowd->draw(app);
			app.display();

//			if (!(rand() % 10))
//				std::cout << "On map: " << Pieton::population <<std::endl;
		}

		usleep(30000);
	}
	return 0;
}
