/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 16:24:32 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/23 14:21:24 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORMCLASS_HPP
# define ROBOTOMYREQUESTFORMCLASS_HPP

#	include "Form.hpp"

class RobotomyRequestForm: public Form
{
  public:
	  // Constructors and destructors
	  RobotomyRequestForm(void);
	  RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm(std::string const & targert);
		virtual ~RobotomyRequestForm(void);

		// operator
		RobotomyRequestForm		&operator=(const RobotomyRequestForm&src);

		virtual void execute(Bureaucrat const & user) const;

};

#endif
