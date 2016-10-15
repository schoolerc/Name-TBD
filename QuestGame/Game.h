#pragma once
#include "WindowConfiguration.h"
#include <SFML/Window.hpp>
class Game
{
public:
	Game();
	~Game();

	void Init();
	void Run();
	void Shutdown();

private:
	WindowConfiguration window_config;
	sf::Window window;

	const std::string DefaultWindowConfigPath = "window.json";
};

