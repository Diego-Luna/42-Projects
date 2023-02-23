/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:21:38 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/23 14:22:13 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_H
# define SHRUBBERYCREATIONFORM_H

# include <iostream>
# include <fstream>
# include "Form.hpp"

class ShrubberyCreationForm: public Form {

public:

		ShrubberyCreationForm();
    ShrubberyCreationForm(const ShrubberyCreationForm&);
		ShrubberyCreationForm(const std::string target);
		virtual ~ShrubberyCreationForm();
		virtual void execute(Bureaucrat const & user) const;

		ShrubberyCreationForm &operator=(const ShrubberyCreationForm&);

};

#endif
