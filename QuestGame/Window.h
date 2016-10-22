#pragma once
#include <Windows.h>
#undef CreateWindow
namespace game
{
	struct Window {
		HWND handle;
		HDC device_context;
		HGLRC opengl_context;
	};
	
	struct WindowConfiguration {
		int width, height;
	};

	void RegisterWindowClass;

	Window CreateWindow(WindowConfiguration);
}