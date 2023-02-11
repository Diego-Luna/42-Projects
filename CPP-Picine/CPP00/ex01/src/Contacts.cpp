#include "Contacts.hpp"

Contact::Contact(void) : _first_name(""), _last_name(""),  _nickname(""), _phone_number(""), 	_darkest_secret("") {
	// std::cout << "Contact created" << std::endl;
}

Contact::~Contact(void){
	// std::cout << "Contact destroyed" << std::endl;
}


void		Contact::_print_contact_all(int i)
{
	std::cout << "-> index : ";
	std::cout << i;
	std::cout << "\n";

	std::cout << "-> first_name :"  + this->_first_name  + "\n";
	std::cout << "-> last_name :"  + this->_last_name  + "\n";
	std::cout << "-> nickname :"  + this->_nickname  + "\n";
	std::cout << "-> phone_number :"  + this->_phone_number + "\n";
	std::cout << "-> darkest_secret :"  + this->_darkest_secret + "\n";
}

void		Contact::_print_info(std::string	buffer)
{
	std::string	tem;

	if (buffer.length() > 10)
	{
		buffer = buffer.substr(0,9);
		buffer.append(".");
	}
	else if (buffer.length() < 10)
	{
		tem = buffer;
		buffer = "";
		for (size_t i = 0; i + tem.length() < 10; i++)
		{
			buffer.append(" ");
		}
		buffer.append(tem);
	}

	std::cout << buffer;
}

void		Contact::_print_contact(int i)
{
	std::cout << "|         ";
	std::cout << i;
	std::cout << "|";
	// std::cout << this->_first_name ;
	_print_info(this->_first_name);
	std::cout << "|";
	// std::cout << this->_last_name ;
	_print_info(this->_last_name);
	std::cout << "|" ;
	// std::cout << this->_nickname  ;
	_print_info(this->_nickname );
	std::cout << "|\n" ;
}

std::string Contact::_get_data(std::string msg)
{
	std::string	buffer;

	buffer = "";
	while (buffer.length() < 1)
	{
		std::cout << "> ";
		std::cout << msg;
		std::cout << " : ";
		std::getline(std::cin, buffer);
	}
	return (buffer);
}

void	Contact::_create(void)
{
	this->_first_name = _get_data("first_name");
	this->_last_name = _get_data("last_name");
	this->_nickname = _get_data("nickname");
	this->_phone_number = _get_data("phone_number");
	this->_darkest_secret = _get_data("darkest_secret");
}
