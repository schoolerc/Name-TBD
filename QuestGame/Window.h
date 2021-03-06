#pragma once

#include <string>
#include <memory>

#include <Windows.h>

#include "Event.h"

namespace game
{
	class Game;
	class WindowConfiguration;
	class Window
	{
	public:
		Window(Game*);
		~Window();

		void Create(WindowConfiguration*);
		void Show();
		void Close();
		void PumpMessages();


	private:
		Game* game;
		HWND handle;
		HDC device_context;
		HGLRC opengl_context;

		void RegisterWindowClass();

		const std::string window_class_name = "GameWindowClass";

		static LRESULT __stdcall WindowProcedure(HWND, UINT, WPARAM, LPARAM);
		long WindowProcedure(UINT, WPARAM, LPARAM);

		std::shared_ptr<Event> ConstructGameEvent(UINT, WPARAM, LPARAM);
		std::shared_ptr<MouseEvent> ConstructMouseEvent(UINT, WPARAM, LPARAM);
		std::shared_ptr<KeyEvent> ConstructKeyEvent(UINT, WPARAM, LPARAM);
		std::shared_ptr<ResizeEvent> ConstructResizeEvent(UINT, WPARAM, LPARAM);
	};
}