/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:26:52 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/21 12:21:39 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include <iostream>
# include "Animal.hpp"

class Cat : public Animal
{
  public:
	  // Constructors and destructors
	  Cat(void);
	  Cat(const Cat &src);
	  virtual ~Cat(void);
		virtual void		makeSound(void) const;

		std::string			getType(void) const;

		Cat		&operator=(const Cat &src);

};

#endif
