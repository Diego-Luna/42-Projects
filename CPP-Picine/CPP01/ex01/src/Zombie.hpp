/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 11:27:45 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/14 11:56:56 by dluna-lo         ###   ########.fr       */
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
	  Zombie(void);
	  ~Zombie(void);

	void set_name(std::string name);
	void announce(void);

  private:
		std::string 	_name;
};

Zombie* zombieHorde( int N, std::string name );

#endif