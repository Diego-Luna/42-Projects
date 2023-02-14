/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 12:51:27 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/14 13:15:09 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_CLASS_HPP
# define WEAPON_CLASS_HPP

# include <iostream>
# include <string>

class Weapon
{
  public:
	  // Constructors and destructors
	  Weapon(std::string 	newType);
	  ~Weapon(void);

	std::string	&getType(void);
	void	setType(std::string newType);

  private:
		std::string 	_type;
};

#endif