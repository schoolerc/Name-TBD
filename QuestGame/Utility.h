#pragma once

#include <string>

namespace game
{
	void CheckError();

	std::string GetFileContents(const std::string& filename);
}