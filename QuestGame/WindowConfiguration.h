#pragma once
#include <string>
class WindowConfiguration
{
public:
	WindowConfiguration();
	~WindowConfiguration();

	int GetWidth();
	int GetHeight();

	int GetGlMajor();
	int GetGlMinor();

	const std::string& GetTitle();

	void SetWidth(int);
	void SetHeight(int);

	void SetGlMajor(int);
	void SetGlMinor(int);

	void SetTitle(const std::string&);

	void Load(const std::string&);
	void Save(const std::string&);

private:
	int width = 0;
	int height = 0;

	int gl_major = 0;
	int gl_minor = 0;

	std::string title = "";
};

