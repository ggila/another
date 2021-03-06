/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Foule.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/15 02:04:30 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/16 20:27:29 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FOULE_HPP
# define FOULE_HPP

# include "another.h"
#include "Pieton.hpp"

class Foule{

// This is a Singleton
	public:
		static Foule	*instance(void);
	private:
		static Foule	*_single;
		Foule(void);

	public:
		void	newPieton(void);
		void	draw(sf::RenderWindow &app);
		void	move(void);

		Pieton	_foule[MAXFOULESIZE];
	private:
};

#endif
