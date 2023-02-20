/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/20 18:26:52 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/20 18:30:18 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_CLASS_HPP
# define CAT_CLASS_HPP

# include <iostream>

class Cat
{
  public:
	  // Constructors and destructors
	  Cat(void);
	  Cat(const int value);
	  Cat(const float value);
	  Cat(const Cat &src);
	  ~Cat(void);

  protected:
		std::string type;
};

#endif
