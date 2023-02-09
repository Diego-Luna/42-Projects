/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 08:36:47 by diegofranci       #+#    #+#             */
/*   Updated: 2023/02/09 10:10:48 by diegofranci      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_CLASS_HPP
# define PHONEBOOK_CLASS_HPP

// #include "Contacts.hpp"
# include <iostream>
# include <string>

class PhoneBook
{

public:

	// Constructors and destructors
	PhoneBook(void);
	~PhoneBook(void);

	//Main function to use the phonebook
	void		start_phonebook(void);

private:

	// Attributes can only be accessed by the class itself
	int const	_max_contacts;
	int		 	_nb_contacts;
	// Contact 	_contacts[8];

	// Private functions to manage the contacts
	void		_add_contact(void);
	void		_search_contact(void);

};

#endif
