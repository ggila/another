/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Pieton.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggilaber <ggilaber@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/14 01:18:52 by ggilaber          #+#    #+#             */
/*   Updated: 2015/11/14 05:33:03 by ggilaber         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIETON_HPP
# define PIETON_HPP

# include "another.h"

class Pieton {
	public:
		Pieton();
		void			move(void);
		bool			out(void);
		operator		sf::CircleShape() {return this->_img;};

	private:
		sf::CircleShape	_img;
		char			_speed;
		int				_pos[2];
		double			_dir[2];
};

#endif
