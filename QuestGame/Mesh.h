#pragma once
#include "Resource.h"
class Mesh :
	public Resource
{
public:
	Mesh(const std::string& name);
	~Mesh();

	void Load(const std::string& filename);

private:

};

