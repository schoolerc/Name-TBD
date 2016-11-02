#include "Window.h"

#include <iostream>

#include "WindowConfiguration.h"
#include "Utility.h"
#include "Game.h"

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
			SetWindowLongA(handle, GWLP_USERDATA, (long)window);
		}
		window = (Window*)GetWindowLongA(handle, GWLP_USERDATA);

		if (window != nullptr)
		{
			return window->WindowProcedure(message, w, l);
		}
		else
		{
			return DefWindowProcA(handle, message, w, l);
		}
	}

	std::shared_ptr<Event> Window::ConstructGameEvent(UINT message, WPARAM w, LPARAM l)
	{
		switch (message)
		{
		case WM_MOUSEMOVE:
		case WM_LBUTTONDOWN:
		case WM_LBUTTONUP:
		case WM_LBUTTONDBLCLK:
		case WM_RBUTTONDOWN:
		case WM_RBUTTONUP:
		case WM_RBUTTONDBLCLK:
		case WM_MBUTTONDOWN:
		case WM_MBUTTONUP:
		case WM_MBUTTONDBLCLK:
			return ConstructMouseEvent(message, w, l);

		case WM_KEYDOWN:
		case WM_KEYUP:
			return ConstructKeyEvent(message, w, l);

		case WM_SIZE:
			return ConstructResizeEvent(message, w, l);

		default:
			return nullptr;
		}
	}

	long Window::WindowProcedure(UINT message, WPARAM w, LPARAM l)
	{
		std::shared_ptr<Event> event = ConstructGameEvent(message, w, l);
		game->Event(event.get());
	}

	void Window::Create(WindowConfiguration* window_configuration)
	{
		RegisterWindowClass();

		handle = CreateWindowExA(0,
			window_class_name.c_str(),
			window_configuration->GetTitle().c_str(),
			WS_OVERLAPPED | WS_CAPTION,
			CW_USEDEFAULT,
			CW_USEDEFAULT,
			window_configuration->GetWidth(),
			window_configuration->GetHeight(),
			nullptr,
			nullptr,
			GetModuleHandle(nullptr),
			this);
		CheckError();
	}

	void Window::Close()
	{
		DestroyWindow(handle);
		CheckError();
		handle = nullptr;
	}

	void Window::Show()
	{
		ShowWindow(handle, SW_SHOW);
		CheckError();
	}

	void Window::RegisterWindowClass()
	{
		WNDCLASSEXA window_class_definition;
		memset(&window_class_definition, 0, sizeof(window_class_definition));

		window_class_definition.cbSize = sizeof(window_class_definition);
		window_class_definition.hInstance = GetModuleHandle(nullptr);
		window_class_definition.lpfnWndProc = Window::WindowProcedure;
		window_class_definition.lpszClassName = window_class_name.c_str();
		window_class_definition.style = CS_OWNDC;

		RegisterClassExA(&window_class_definition);
		CheckError();
	}

	void Window::PumpMessages()
	{
		MSG message;
		while (PeekMessageA(&message, 0, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessageA(&message);
		}
	}
}