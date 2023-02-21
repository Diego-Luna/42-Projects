/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:26:52 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/20 20:56:29 by diegofranci      ###   ########.fr       */
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

  protected:
		std::string type;
};

#endif
