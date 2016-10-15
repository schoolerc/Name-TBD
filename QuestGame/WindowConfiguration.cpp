#include "WindowConfiguration.h"
#include <rapidjson/document.h>
#include <rapidjson/writer.h>
#include <rapidjson/filewritestream.h>
#include <fstream>

WindowConfiguration::WindowConfiguration()
{
}


WindowConfiguration::~WindowConfiguration()
{
}

void WindowConfiguration::SetGlMajor(int major)
{
	gl_major = major;
}

void WindowConfiguration::SetGlMinor(int minor)
{
	gl_minor = minor;
}

void WindowConfiguration::SetWidth(int w)
{
	width = w;
}

void WindowConfiguration::SetHeight(int h)
{
	height = h;
}

void WindowConfiguration::SetTitle(const std::string& t)
{
	title = t;
}

const std::string& WindowConfiguration::GetTitle()
{
	return title;
}

int WindowConfiguration::GetGlMajor()
{
	return gl_major;
}

int WindowConfiguration::GetGlMinor()
{
	return gl_minor;
}

int WindowConfiguration::GetWidth()
{
	return width;
}

int WindowConfiguration::GetHeight()
{
	return height;
}

void WindowConfiguration::Load(const std::string& filename)
{
	std::ifstream file(filename);
	rapidjson::Document doc;
	doc.ParseStream(file);

	width = doc["width"].GetInt();
	height = doc["height"].GetInt();

	gl_major = doc["gl_major"].GetInt();
	gl_minor = doc["gl_minor"].GetInt();

	title = doc["title"].GetString();
}

void WindowConfiguration::Save(const std::string& filename)
{
	rapidjson::Document doc;

	doc["width"].SetInt(width);
	doc["height"].SetInt(height);
	
	doc["gl_major"].SetInt(gl_major);
	doc["gl_minor"].SetInt(gl_minor);

	doc["title"].SetString(title.c_str(), title.size());

	char buf[1024];
	FILE* f = fopen(filename.c_str(), "wb");
	rapidjson::FileWriteStream fws(f, buf, 1024);
	rapidjson::Writer<rapidjson::FileWriteStream> writer;
	doc.Accept(writer);
}