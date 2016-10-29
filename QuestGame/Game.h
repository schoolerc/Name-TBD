#pragma once

#include <string>

#include "WindowConfiguration.h"
#include "Event.h"

namespace game {
	class Window;

	enum class GameState
	{
		Starting,
		MainMenu,
		Loading,
		Running,
		Closing,
		Done
	};

	class Game
	{
	public:
		Game();
		~Game();

		WindowConfiguration* GetWindowConfiguration();

		void LoadConfiguration();
		bool IsRunning();
		void Event(Event*);

	protected:
		void ResizeEvent(ResizeEvent*);
		void UpdateEvent(UpdateEvent*);
		void MouseMoveEvent(MouseEvent*);
		void MouseButtonPress(MouseEvent*);
		void MouseButtonReleased(MouseEvent*);
		void MouseDoubleClicked(MouseEvent*);
		void KeyDownEvent(KeyEvent*);
		void KeyUpEvent(KeyEvent*);

	private:
		Window* window;

		WindowConfiguration window_configuration;
		const std::string window_configuration_path;

		bool running = true;

	};

}