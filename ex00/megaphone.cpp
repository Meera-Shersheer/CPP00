#include <iostream>
#include <string>
#include <cctype>



std::string str_toupper(std::string word)
{
	for(size_t  i = 0; i < word.length() ; i++)
		word[i] = std::toupper(word[i]);
	return word;
}


int main(int argc, char **argv)
{
	if (argc > 1)
	{
		for(int i = 1; i < argc; i++)
			std::cout<< str_toupper(argv[i]);
		std::cout<< std::endl;	
	}
	else
		std::cout<< "* LOUD AND UNBEARABLE FEEDBACK NOISE *"<< std::endl;

	return 0;
}
