/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:07:16 by diegofranci       #+#    #+#             */
/*   Updated: 2023/02/10 18:36:34 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_CLASS_HPP
# define CONTACT_CLASS_HPP

# include <iostream>
# include <string>

class Contact
{
  public:
	  // Constructors and destructors
	  Contact(void);
	  ~Contact(void);

		void		_print_contact(int i);
		void		_print_contact_all(int i);
		void		_create(void);

  private:

		std::string _get_data(std::string msg);

    // Attributes can only be accessed by the class itself
	  std::string 	_first_name;
	  std::string 	_last_name;
	  std::string 	_nickname;
	  std::string 	_phone_number;
	  std::string 	_darkest_secret;
};

#endif