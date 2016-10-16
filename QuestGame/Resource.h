#pragma once
#include <string>
class Resource
{
public:
	Resource(const std::string& name);
	~Resource();

	const std::string& GetName() { return name; }

private:
	std::string name;
};

