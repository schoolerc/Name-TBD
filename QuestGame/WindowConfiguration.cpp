#include "WindowConfiguration.h"

#include <fstream>

#include <rapidjson\document.h>

namespace game {

	WindowConfiguration::WindowConfiguration()
	{
	}


	WindowConfiguration::~WindowConfiguration()
	{
	}

	int WindowConfiguration::GetWidth()
	{
		return width;
	}

	int WindowConfiguration::GetHeight()
	{
		return height;
	}

	bool WindowConfiguration::GetFullscreen()
	{
		return fullscreen;
	}

	std::string WindowConfiguration::GetTitle()
	{
		return title;
	}

	void WindowConfiguration::SetWidth(int w)
	{
		width = w;
	}

	void WindowConfiguration::SetHeight(int h)
	{
		height = h;
	}

	void WindowConfiguration::SetFullscreen(bool f)
	{
		fullscreen = f;
	}

	void WindowConfiguration::SetTitle(const std::string& t)
	{
		title = t;
	}

	void WindowConfiguration::Load(const std::string& path)
	{
		std::ifstream config_stream(path);
		rapidjson::Document document;
		document.ParseStream(config_stream);

		width = document["width"].GetInt();
		height = document["height"].GetInt();
		fullscreen = document["fullscreen"].GetInt();
		title = document["title"].GetString();
	}
}