#pragma once

#include <memory>
#include <string>
#include <unordered_map>

#include <freetype/freetype.h>

#include "Text.h"

namespace game {
	class TextManager
	{
	public:
		TextManager();
		~TextManager();

		std::shared_ptr<Text> CreateTextObject(const std::string& text);

	private:
		FT_Library freetype_library;
		FT_Face freetype_face;

		std::unordered_map<char, unsigned int> character_textures;
	};

}