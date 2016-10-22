#include <iostream>
#include <stdexcept>
#include <string>
#include <gl/glew.h>
#include <Windows.h>
#include <wingdi.h>
static bool running = true;

void __stdcall DebugProc(GLenum source, GLenum type, GLuint id, GLenum severity, GLsizei length, const GLchar* message, const void* userParam)
{
	std::cout << message << std::endl;
}

LRESULT __stdcall MainWindowProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	if (message == WM_CLOSE)
	{
		running = false;
		PostQuitMessage(0);
		return 0;
	}
	return DefWindowProcA(hwnd, message, wParam, lParam);
}


int __stdcall WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int)
{
	try {
		AllocConsole();
		WNDCLASSEX wndclass;
		memset(&wndclass, 0, sizeof(wndclass));
		wndclass.cbSize = sizeof(wndclass);
		wndclass.hInstance = instance;
		wndclass.lpszClassName = "QuestGameWindowClass";
		wndclass.style = CS_OWNDC;
		wndclass.lpfnWndProc = MainWindowProc;

		RegisterClassEx(&wndclass);

		HWND window = CreateWindowExA(0,
			"QuestGameWindowClass",
			"Test",
			WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT, CW_USEDEFAULT,
			800, 600,
			nullptr, nullptr, instance, nullptr);
		
		HDC device_context = GetDC(window);

		PIXELFORMATDESCRIPTOR pixel_format_desc;
		memset(&pixel_format_desc, 0, sizeof(pixel_format_desc));
		pixel_format_desc.nSize = sizeof(pixel_format_desc);
		pixel_format_desc.nVersion = 1;
		pixel_format_desc.dwFlags = PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER;
		pixel_format_desc.iPixelType = PFD_TYPE_RGBA;
		pixel_format_desc.cColorBits = 32;
		pixel_format_desc.cDepthBits = 24;
		pixel_format_desc.cStencilBits = 8;
		pixel_format_desc.iLayerType = PFD_MAIN_PLANE;

		int pixel_format_index = ChoosePixelFormat(device_context, &pixel_format_desc);
		SetPixelFormat(device_context, pixel_format_index, &pixel_format_desc);

		HGLRC opengl_context = wglCreateContext(device_context);
		wglMakeCurrent(device_context, opengl_context);
		auto err = GLEW_OK;
		err = glewInit();

		if (GLEW_KHR_debug)
		{
			glDebugMessageCallback(DebugProc, nullptr);
		}

		ShowWindow(window, SW_SHOW);
		UpdateWindow(window);

		
		double color = 1.0f;
		double delta = .0005;
		MSG message;
		while (running)
		{
			while (PeekMessageA(&message, nullptr, 0, 0, PM_REMOVE))
			{
				TranslateMessage(&message);
				DispatchMessage(&message);
			}
			glClearColor(color, 1 - color, 0.0, 1.0);
			glClear(GL_COLOR_BUFFER_BIT);
			SwapBuffers(device_context);

			color += delta;
			if (color > 1 || color < 0)
			{
				delta = -delta;
			}
		}
	}
	catch(std::exception& ex){
		std::cout << ex.what() << std::endl;
		std::cout << "Press enter to exit";
		std::string tmp;
		std::cin >> tmp;
	}
}