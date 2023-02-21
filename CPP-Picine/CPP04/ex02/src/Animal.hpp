/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:26:51 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/21 13:04:09 by dluna-lo         ###   ########.fr       */
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
		virtual void		makeSound(void) const = 0;

		std::string	getType(void) const;

		Animal		&operator=(Animal const & src);

  protected:
		std::string	_type;
};

#endif
