#pragma once

#include <string>

#include "WindowConfiguration.h"

namespace game {
	class Window;
	class Event;
	class Game
	{
	public:
		Game();
		~Game();

		WindowConfiguration* GetWindowConfiguration();

		void LoadConfiguration();

		void Event(Event*);

	private:
		Window* window;

		WindowConfiguration window_configuration;
		const std::string window_configuration_path;

	};

}