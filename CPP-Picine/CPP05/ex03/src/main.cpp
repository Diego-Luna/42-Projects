/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/08 13:51:10 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/08 13:51:12 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Intern.hpp"
#include "Bureaucrat.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	std::cout << "-----------------create-----------------" << std::endl;
  Intern user;
	Form* newForm;


	std::cout << "\n\n-----------------teste 1 : robotomy request-----------------" << std::endl;
	try
	{
		newForm = user.makeForm("robotomy request", "Ramen");
		Bureaucrat Paco("Paco", 20);
		std::cout << Paco << std::endl;
		Paco.signForm(*newForm);
		Paco.executeForm(*newForm);
		delete newForm;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n\n-----------------teste 2 : ShrubberyCreationForm-----------------" << std::endl;
	try
	{
		newForm = user.makeForm("shrubbery request", "Taco");
		Bureaucrat Diego("Diego", 20);
		Diego.signForm(*newForm);
		Diego.executeForm(*newForm);
		delete newForm;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << "\n\n-----------------teste 3 :ShrubberyCreationForm-----------------" << std::endl;
	try
	{
		newForm = user.makeForm("presidential request", "Putting");
		Bureaucrat Francisco("Francisco", 20);
		Francisco.signForm(*newForm);
		Francisco.executeForm(*newForm);
		delete newForm;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}


	std::cout << "\n\n-----------------teste 4 : name no valid-----------------" << std::endl;
	try
	{
		newForm = user.makeForm("hello World", "42");
		delete newForm;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

  return 0;
}