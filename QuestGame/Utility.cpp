#include "Utility.h"

#include <Windows.h>

namespace game
{
	void CheckError()
	{
		int err = GetLastError();
		if (err != NOERROR)
		{
			char buffer[1024];
			FormatMessageA(FORMAT_MESSAGE_FROM_SYSTEM, nullptr, err, 0, buffer, 1024, nullptr);
			throw std::runtime_error(std::string(buffer));
		}
	}

	std::string GetFileContents(const std::string& filename)
	{
		HANDLE file = CreateFileA(filename.c_str(), GENERIC_READ, FILE_SHARE_READ, nullptr, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, nullptr);
		CheckError();

		long file_size = GetFileSize(file, nullptr);
		CheckError();

		std::string buffer;
		buffer.resize(file_size);

		ReadFile(file, &buffer[0], file_size, nullptr, nullptr);
		CheckError();

		return buffer;

	}
}