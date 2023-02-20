/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:26:51 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/20 18:29:56 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_CLASS_HPP
# define ANIMAL_CLASS_HPP

# include <iostream>

class Animal
{
  public:
	  // Constructors and destructors
	  Animal(void);
	  Animal(const int value);
	  Animal(const float value);
	  Animal(const Animal &src);
	  ~Animal(void);

  protected:
		std::string type;
};

#endif
