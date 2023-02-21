/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 08:34:10 by diegofranci       #+#    #+#             */
/*   Updated: 2023/02/21 08:34:15 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include <iostream>
#include "WrongAnimal.hpp"

class WrongCat : public WrongAnimal
{
public:

	WrongCat(void);
	WrongCat(const WrongCat &src);
	virtual ~WrongCat(void);

	WrongCat		&operator=(const WrongCat &src);
	
	std::string			getType(void) const;
	void		makeSound(void) const;
};

#endif
