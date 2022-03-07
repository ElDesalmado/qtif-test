#include "component_a.h"

#include <iterator>
#include <iostream>

DLL_API bool get_version(char* buffer, unsigned int size)
{
	constexpr const char version[] = "0.0.1";

	if (size < std::size(version))
	{
		std::cerr << "Error: insufficient buffer \"" << __func__ << "\"" << std::endl;
		return false;
	}

	std::copy(version, version + std::size(version), buffer);
	return true;
}
