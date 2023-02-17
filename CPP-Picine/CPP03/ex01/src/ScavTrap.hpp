/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/17 17:55:56 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/17 18:18:10 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_CLASS_HPP
# define SCAVTRAP_CLASS_HPP

# include <iostream>
#	include "ClapTrap.hpp"

class ScavTrap : public ClapTrap
{
  public:
	  ScavTrap(void);
	  ScavTrap(std::string name);
	  ScavTrap(ScavTrap const &src);
	  ~ScavTrap(void);

		ScavTrap &operator=(const ScavTrap &src);

		void guardGate(void);

  private:
};

#endif
