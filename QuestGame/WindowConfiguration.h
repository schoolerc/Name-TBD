#pragma once

#include <string>

namespace game {
	class WindowConfiguration
	{
	public:
		WindowConfiguration();
		~WindowConfiguration();

		void Load(const std::string& path);
		void Save(const std::string& path);

		int GetWidth();
		int GetHeight();
		std::string GetTitle();
		bool GetFullscreen();

		void SetWidth(int);
		void SetHeight(int);
		void SetTitle(const std::string&);
		void SetFullscreen(bool);

	private:
		int width;
		int height;
		bool fullscreen;
		std::string title;
	};

}