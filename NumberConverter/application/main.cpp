
#include <iostream>
#include <NumberConverter.hpp>

int main()
{
	std::cout << "Intoduce the senteces with numbers that you want to convert." << std::endl;
	std::cout << "Intoduce 'exit' for quit." << std::endl;

	std::string text;

	NumberConverter converter;

	while (std::getline(std::cin , text))
		{
			if (text == "exit") break;
			std::cout << converter.convert(text) << std::endl;

		}

	return 0;
}
