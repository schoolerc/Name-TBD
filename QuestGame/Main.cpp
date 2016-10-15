#include <iostream>
#include <stdexcept>
#include <string>
#include <SFML/Window.hpp>

int main(int argc, const char* argv[])
{
	try {
		sf::Window()
		return 0;
	}
	catch(std::exception& ex){
		std::cout << ex.what() << std::endl;
	}
	std::cout << "Press enter to exit";
	std::string tmp;
	std::cin >> tmp;
}