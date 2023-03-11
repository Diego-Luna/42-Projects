/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dluna-lo <dluna-lo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 17:04:19 by dluna-lo          #+#    #+#             */
/*   Updated: 2023/03/10 17:38:13 by dluna-lo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
# define DATA_HPP


# include <iostream>

struct Data {
  std::string name;
  int i;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif
