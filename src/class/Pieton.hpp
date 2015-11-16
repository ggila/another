/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pieton.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 01:18:52 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/16 19:45:34 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIETON_HPP
# define PIETON_HPP

# include "another.h"

class Pieton {
	public:
		static int			population;

		Pieton();
		void				move(Pieton crowd[]);
		bool				out(void);
		void				born(void);
		void				die(void);

		sf::CircleShape		getImg(void);
		int					getX(void);
		int					getY(void);
		bool				isAlive(void);

	private:
		bool				_alive;
		sf::CircleShape		_img;
		char				_speed;
		int					_pos[2];
		double				_dir[2];

		bool				_collide(Pieton &that);
};

#endif
