#include "Window.h"
namespace game
{
	Window::Window(Game* g) : game(g)
	{
	}

	Window::~Window()
	{
	}

	LRESULT __stdcall Window::WindowProcedure(HWND handle, UINT message, WPARAM w, LPARAM l)
	{
		Window* window;

		if (message == WM_CREATE)
		{
			window = (Window*)((CREATESTRUCTA*)l)->lpCreateParams;
			SetWindowLongA(handle, GWL_USERDATA, (long)window);
		}
		window = (Window*)GetWindowLongA(handle, GWL_USERDATA);

		if (window != nullptr)
		{
			return window->WindowProcedure(message, w, l);
		}
		else
		{
			return DefWindowProcA(handle, message, w, l);
		}
	}

	long Window::WindowProcedure(UINT message, WPARAM w, LPARAM l)
	{
		switch (message)
		{
		case WM_NCCREATE:
			return 1;
		case WM_CREATE:
			return 0;
		case WM_SIZE:
			return 
		}
	}
}