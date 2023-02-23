/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:21:29 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/23 14:21:32 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: Form("ShrubberyCreationForm", "Default", false, 145, 137){

}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& src) : 
        Form(src.getName(),
        src.getTarget(),
        src.getSigned(),
        src.getGradeSingIn(),
        src.getGradeExecute()){
}

ShrubberyCreationForm::ShrubberyCreationForm(const std::string target): 
        Form("ShrubberyCreationForm", target, false, 145, 137) {

}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
        return;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm&) {
	return *this;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

	validateExecute(executor);
	std::ofstream outfile((getTarget() + "_shrubbery").c_str());

	std::string shrubbery =
"         *\n\
        /|\\\n\
       /*|O\\\n\
      /*/|\\*\\\n\
     /X/O|*\\X\\\n\
    /*/X/|\\X\\*\\\n\
   /O/*/X|*\\O\\X\\\n\
  /*/O/X/|\\X\\O\\*\\\n\
 /X/O/*/X|O\\X\\*\\O\\\n\
/O/X/*/O/|\\X\\*\\O\\X\\\n\
        |X|\n\
        |X|\n";

	outfile << shrubbery;
}
