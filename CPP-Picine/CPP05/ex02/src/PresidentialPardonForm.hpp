/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 21:13:26 by diegofranci       #+#    #+#             */
/*   Updated: 2023/02/23 09:43:00 by diegofranci      ###   ########.fr       */
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
