/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 12:03:47 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/21 12:23:11 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_CLASS_HPP
# define BRAIN_CLASS_HPP

# include <iostream>

class Brain
{
  public:
	  // Constructors and destructors
	  Brain(void);
	  Brain(const Brain &src);
		~Brain(void);

		std::string	ideas[100];

		Brain		&operator=(Brain const & src);
};

#endif
