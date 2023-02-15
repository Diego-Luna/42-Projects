

#include <string>
#include <iostream>
#include <fstream>


int	return_error(std::string  line)
{
	std::cout << " Error in: " << line << "\n" << std::endl;
	return 1;
}

int main(int arg, char **argv) {

	std::ifstream	Infile;
	std::ofstream	Outfile;
	std::string  name, find, replace;
	std::string  line;
	size_t tem;

	if (arg != 4)
		return return_error(" required [filename] [strings to search] [strings to replace]");
	name = argv[1];
	find = argv[2];
	replace = argv[3];

	Infile.open(name);
	if (!Infile.is_open())
		return return_error(name);
	Outfile.open(name + ".replace");
	if (!Outfile.is_open())
		return return_error(name);
	line = "";
	while (std::getline(Infile, line))
	{
		tem = line.find(find);
		if (tem != std::string::npos)
		{
			while (tem != std::string::npos)
			{
				line.erase(tem, find.length());
				line.insert(tem, replace);
				tem = line.find(find, tem + replace.length());
			}
		}
		Outfile << line << std::endl;
	}
	Outfile.close();
	return 1;
}
