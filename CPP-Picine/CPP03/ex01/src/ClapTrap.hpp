/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:12:22 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/17 18:19:11 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_CLASS_HPP
# define CLAPTRAP_CLASS_HPP

# include <iostream>

class ClapTrap
{
  public:
	  ClapTrap(void);
	  ClapTrap(std::string name);
	  ClapTrap(ClapTrap const &src);
	  ~ClapTrap(void);

		ClapTrap &operator=(const ClapTrap &src);

		void attack(const std::string& target);
		void takeDamage(unsigned int amount);
		void beRepaired(unsigned int amount);

		std::string getName(void);

  protected:
		std::string _name;
		int _hit;
		int _energy;
		int _attack;
};

#endif
