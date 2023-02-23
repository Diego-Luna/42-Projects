/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:21:10 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/23 14:21:12 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() :
		Form("PresidentialPardonForm", "Default", false, 25, 5) {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm& src) :
		Form(
		src.getName(),
		src.getTarget(),
		src.getSigned(),
		src.getGradeSingIn(),
		src.getGradeExecute()
	) {
}

PresidentialPardonForm::PresidentialPardonForm(const std::string target):
		Form("PresidentialPardonForm", target, false, 25, 5) {
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm&) {
	return *this;
}

void PresidentialPardonForm::execute(Bureaucrat const & user) const {
	validateExecute(user);
	std::cout << getTarget() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
