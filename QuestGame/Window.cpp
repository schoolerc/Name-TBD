#include "Window.h"

#include <iostream>

#include "WindowConfiguration.h"
#include "Utility.h"

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
			return 1;
		}
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