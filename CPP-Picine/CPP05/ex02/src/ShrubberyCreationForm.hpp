/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 20:39:51 by diegofranci       #+#    #+#             */
/*   Updated: 2023/02/22 20:49:51 by diegofranci      ###   ########.fr       */
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
        ShrubberyCreationForm &operator=(const ShrubberyCreationForm&);
		
		virtual void execute(Bureaucrat const & user) const;
};

#endif
