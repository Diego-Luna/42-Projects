/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:14:31 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/14 13:30:24 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANA_CLASS_HPP
# define HUMANA_CLASS_HPP

# include <iostream>
# include <string>
# include "./Weapon.hpp"

class HumanA
{
  public:
	  // Constructors and destructors
	  HumanA(std::string 	name, Weapon &_weapon);
	  ~HumanA(void);

		void attack(void);

  private:
		std::string 	_name;
		Weapon &_weapon;
};

#endif
