/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:42:18 by diegofranci       #+#    #+#             */
/*   Updated: 2023/02/23 09:48:35 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {
   std::cout << "-----------------ShrubberyCreationForm-----------------" << std::endl;
	Bureaucrat dixie("dixie", 20);
	ShrubberyCreationForm form1("Christmas tree");
	std::cout << dixie;
	dixie.signForm(form1);
	dixie.executeForm(form1);
	std::cout << std::endl;

	std::cout << "-----------------RobotomyRequestForm-----------------" << std::endl;
	Bureaucrat lala("lala", 46);
	RobotomyRequestForm form2("po");
	std::cout << lala << std::endl;
	lala.signForm(form2);
	lala.executeForm(form2);
	dixie.executeForm(form2);
	std::cout << std::endl;

	std::cout << "-----------------PresidentialPardonForm-----------------" << std::endl;
	Bureaucrat tinky("tinky", 2);
	PresidentialPardonForm form3("winky");
	std::cout << tinky;
	lala.signForm(form3);
	tinky.signForm(form3);
	tinky.executeForm(form3);

    return 0;
}