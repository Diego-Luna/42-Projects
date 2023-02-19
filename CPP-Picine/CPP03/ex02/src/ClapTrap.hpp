/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 12:12:22 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/18 16:33:50 by diegofranci      ###   ########.fr       */
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

		std::string getName(void) const;
		int			getHit(void) const;
		int			getEnergy(void) const;
		int			getAttack(void) const;

  protected:
		std::string _name;
		std::string _type;
		int _hit;
		int _energy;
		int _attack;
};

#endif
