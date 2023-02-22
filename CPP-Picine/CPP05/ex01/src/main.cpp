/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:42:18 by diegofranci       #+#    #+#             */
/*   Updated: 2023/02/21 21:30:47 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main() {
    std::cout << "--------Creating and presenting everyone--------" << std::endl;
    Bureaucrat nobody;
    Bureaucrat taco("taco", 10);
    std::cout << nobody << std::endl;
    std::cout << taco << std::endl;

    std::cout << "\n----addGrade 10 to the grade------" << std::endl;
    try {
      std::cout << "\n----> addGrade: taco" << std::endl;
      taco.addGrade(10);
      std::cout << taco << std::endl;
      std::cout << "\n----> addGrade: nobody" << std::endl;
      nobody.addGrade(10);
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
      std::cout << "\n----> addGrade: nobody" << std::endl;
      nobody.addGrade(100);
      std::cout << nobody << std::endl;
      std::cout << "\n----> addGrade: taco" << std::endl;
      taco.addGrade(100);
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
      std::cout << "\n----> minusGrade: nobody" << std::endl;
      nobody.minusGrade(110);
      std::cout << nobody << std::endl;
      std::cout << "\n----> minusGrade: taco" << std::endl;
      taco.minusGrade(110);
      std::cout << taco << std::endl;
    }
    catch (std::exception& ex) {
      std::cout << ex.what() << std::endl;
    }

    std::cout << "\n---Error" << std::endl;

    return 0;
}