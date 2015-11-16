/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Stress.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/16 14:23:32 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/16 22:25:07 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "another.h"

class	Stress {

// This is a Singleton
	public:
		static Stress	*instance(void);
	private:
		static Stress	*_single;
		Stress(void);

// Stress
	public:
		void	update(Foule *foule);
		void	draw(sf::RenderWindow &app);
//		void	fff(void);

	private:
//		int		*_current;
		char		_tab[HEIGHT][WIDTH];
//		int		_tab2[HEIGHT][WIDTH];
		char		_oneStress[2 * STRESSRAD][2 * STRESSRAD];

		void	_addPieton(Pieton &P);
};
