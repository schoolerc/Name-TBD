#include "Game.h"
#include <SFML/Window.hpp>


Game::Game()
{
}


Game::~Game()
{
}

void Game::Init()
{
	window_config.Load(DefaultWindowConfigPath);
	window.create(
		sf::VideoMode(
			window_config.GetWidth(),
			window_config.GetHeight()),
		window_config.GetTitle(), 
		7U, 
		sf::ContextSettings(
			32, 0, 0, 
			window_config.GetGlMajor(),
			window_config.GetGlMinor()));
}