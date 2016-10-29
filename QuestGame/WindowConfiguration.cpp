#include "WindowConfiguration.h"

#include <rapidjson/document.h>

#include "Utility.h"

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

	void WindowConfiguration::Load(const std::string& filename)
	{
		using namespace rapidjson;
		Document doc;

		std::string raw_config = std::move(GetFileContents(filename));

		doc.Parse(raw_config.c_str());

		width = doc["width"].GetInt();
		height = doc["height"].GetInt();
		fullscreen = doc["fullscreen"].GetBool();
		title = doc["title"].GetString();
	}
}