#include "TextManager.h"

namespace game {

	TextManager::TextManager()
	{
		FT_Init_FreeType(&freetype_library);
		FT_New_Face(freetype_library, "arial.ttf", 0, &freetype_face);
	}


	TextManager::~TextManager()
	{
		FT_Done_Face(freetype_face);
		FT_Done_FreeType(freetype_library);
	}

	std::shared_ptr<Text> TextManager::CreateTextObject(const std::string& text)
	{
		for (auto character : text)
		{
			FT_Load_Char(freetype_face, character, FT_LOAD_RENDER);

			freetype_face->glyph->
		}
		return nullptr;
	}
}