#pragma once
#include <Windows.h>
namespace game
{
	class Game;
	class Window
	{
	public:
		Window(Game*);
		~Window();


	private:
		Game* game;
		HWND handle;
		HDC device_context;
		HGLRC opengl_context;

		static LRESULT __stdcall WindowProcedure(HWND, UINT, WPARAM, LPARAM);
		long WindowProcedure(UINT, WPARAM, LPARAM);

	};
}