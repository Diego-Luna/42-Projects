/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:26:51 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/20 21:25:10 by diegofranci      ###   ########.fr       */
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
	  Animal(std::string type);
	  Animal(const Animal &src);

		virtual ~Animal(void);
		virtual void		makeSound(void) const;

		std::string	getType(void) const;

		Animal		&operator=(Animal const & src);

  protected:
		std::string	_type;
};

#endif
