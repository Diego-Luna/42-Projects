/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   contacts.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: diegofranciscolunalopez <diegofrancisco    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 09:07:16 by diegofranci       #+#    #+#             */
/*   Updated: 2023/02/09 10:08:55 by diegofranci      ###   ########.fr       */
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

  private:
    // Attributes can only be accessed by the class itself
	  std::string 	_first_name;
	  std::string 	_last_name;
	  std::string 	_nickname;
	  std::string 	_phone_number;
	  std::string 	_darkest_secret;
};

#endif