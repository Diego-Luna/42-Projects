/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Humanb.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 15:52:35 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/14 16:21:36 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_CLASS_HPP
# define HUMANB_CLASS_HPP

# include <iostream>
# include <string>
# include "./Weapon.hpp"

class HumanB
{
  public:
	  // Constructors and destructors
	  HumanB(std::string 	name);
	  ~HumanB(void);

		void setWeapon(Weapon &weapon);
		void attack(void);

  private:
		std::string 	_name;
		Weapon *_weapon;
};

#endif
