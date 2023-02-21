/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:30:25 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/20 21:22:47 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_CLASS_HPP
# define DOG_CLASS_HPP

# include <iostream>
# include "Animal.hpp"

class Dog : public Animal
{
  public:
	  // Constructors and destructors
	  Dog(void);
	  Dog(const Dog &src);
	  virtual ~Dog(void);
		virtual void		makeSound(void) const;

		std::string			getType(void) const;

		Dog		&operator=(const Dog &src);

  protected:
		std::string type;
};

#endif
