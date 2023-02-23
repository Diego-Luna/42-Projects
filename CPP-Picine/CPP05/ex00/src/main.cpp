/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:26:33 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/23 14:26:37 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::cout << "--------Creating and presenting everyone--------" << std::endl;
    Bureaucrat nobody;
    Bureaucrat taco("taco", 10);
    std::cout << nobody << std::endl;
    std::cout << taco << std::endl;

    std::cout << "\n----incrementGrade 10 to the grade------" << std::endl;
    try {
      std::cout << "\n----> incrementGrade: taco" << std::endl;
      taco.incrementGrade(10);
      std::cout << taco << std::endl;
      std::cout << "\n----> incrementGrade: nobody" << std::endl;
      nobody.incrementGrade(10);
      std::cout << nobody << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException&ex){
      std::cout << ex.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& ex) {
      std::cout << ex.what() << std::endl;
    }

    std::cout << "\n----add 100 to the grade------" << std::endl;
    try {
      std::cout << "\n----> incrementGrade: nobody" << std::endl;
      nobody.incrementGrade(100);
      std::cout << nobody << std::endl;
      std::cout << "\n----> incrementGrade: taco" << std::endl;
      taco.incrementGrade(100);
      std::cout << taco << std::endl;
    }
    catch (Bureaucrat::GradeTooLowException&ex){
      std::cout << ex.what() << std::endl;
    }
    catch (Bureaucrat::GradeTooHighException& ex) {
      std::cout << ex.what() << std::endl;
    }

    std::cout << "\n---remove 110 to the grade------" << std::endl;
    try {
      std::cout << "\n----> decrementGrade: nobody" << std::endl;
      nobody.decrementGrade(110);
      std::cout << nobody << std::endl;
      std::cout << "\n----> decrementGrade: taco" << std::endl;
      taco.decrementGrade(110);
      std::cout << taco << std::endl;
    }
    catch (std::exception& ex) {
      std::cout << ex.what() << std::endl;
    }

    std::cout << "\n---Error" << std::endl;

    return 0;
}