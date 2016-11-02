#include "Game.h"

#include "Event.h"

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
		window_configuration.SetFullscreen(false);
		window_configuration.SetHeight(600);
		window_configuration.SetWidth(800);
		window_configuration.SetTitle(std::string("Testing"));
	}

	void Game::Event(game::Event* e)
	{

	}

	bool Game::IsRunning()
	{
		return running;
	}

	void Game::SetGameState(GameState new_state)
	{
		switch (state)
		{
		case GameState::Empty:
		{
			if (new_state == GameState::Starting)
			{

			}
			break;
		}
		}
	}

	GameState Game::GetGameState()
	{
		return state;
	}
}