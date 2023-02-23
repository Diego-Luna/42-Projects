/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/23 14:21:18 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/02/23 14:21:18 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#ifndef PRESIDENTIALPARDONFORM_H
#define PRESIDENTIALPARDONFORM_H

#include <iostream>
#include "Form.hpp"

class PresidentialPardonForm: public Form {

public:

		PresidentialPardonForm();
    PresidentialPardonForm(const PresidentialPardonForm&);
		PresidentialPardonForm(const std::string target);

    PresidentialPardonForm &operator=(const PresidentialPardonForm& src);

    virtual ~PresidentialPardonForm();
		virtual void execute(Bureaucrat const & user) const;
};

#endif
