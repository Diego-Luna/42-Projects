/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:27:45 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/14 11:47:01 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_CLASS_HPP
# define ZOMBIE_CLASS_HPP

# include <iostream>
# include <string>

class Zombie
{
  public:
	  // Constructors and destructors
	  Zombie(std::string 	initial_name);
	  ~Zombie(void);

	void announce(void);

  private:
		std::string 	_name;
};

Zombie* newZombie( std::string name );
void randomChump( std::string name );

#endif