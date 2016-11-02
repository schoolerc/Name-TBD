#pragma once

#include <freetype/freetype.h>

namespace game {
	class ResourceManager
	{
	public:
		ResourceManager();
		virtual ~ResourceManager();

	private:
		FT_Library freetype_library;
		FT_Face freetype_default_font;
	};

}