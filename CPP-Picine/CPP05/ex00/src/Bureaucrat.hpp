/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 17:53:28 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/21 18:39:38 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_CLASS_HPP
# define BUREAUCRAT_CLASS_HPP

# include <iostream>

class Bureaucrat
{
  public:
	  // Constructors and destructors
	  Bureaucrat(void);
	  Bureaucrat(std::string _name, int	_grade);
	  Bureaucrat(const Bureaucrat &src);

		std::string getName(void);
		int getGrade(void);

		Bureaucrat		&operator=(Bureaucrat const & src);

  protected:
		std::string	_name;
		int	_grade;
};

#endif
