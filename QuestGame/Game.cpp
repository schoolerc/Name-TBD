#include "Game.h"

namespace game {

	Game::Game()
	{
	}


	Game::~Game()
	{
	}

	WindowConfiguration* Game::GetWindowConfiguration()
	{
		return &window_configuration;
	}

	void Game::LoadConfiguration()
	{
		window_configuration.Load(window_configuration_path);
	}
}