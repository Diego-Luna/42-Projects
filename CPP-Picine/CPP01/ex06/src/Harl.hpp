/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:46:22 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/15 16:21:19 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HARL_CLASS_HPP
# define HARL_CLASS_HPP

# include <iostream>
# include <string>

class Harl
{
  public:
	  // Constructors and destructors
	  Harl(void);
	  ~Harl(void);

		void complain(std::string level);
		int		get_position(std::string str, std::string list[4]);
		void	(Harl::*pointer_function[4]) (void);

  private:

		void debug(void);
		void info(void);
		void warning(void);
		void error(void);
};

#endif
