/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:30:25 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/20 18:30:40 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include <iostream>

class Dog
{
  public:
	  // Constructors and destructors
	  Dog(void);
	  Dog(const int value);
	  Dog(const float value);
	  Dog(const Dog &src);
	  ~Dog(void);

  protected:
		std::string type;
};

#endif
