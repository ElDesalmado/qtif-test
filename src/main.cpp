
#include "component_a.h"

#include <cstddef>
#include <iostream>
#include <vector>

int main(int argc, char **argv)
{
	std::cout << "App version: 0.0.1" << std::endl;

	std::vector componentVersion(16, '\0');

	if (!get_version(componentVersion.data(), componentVersion.size()))
	{
		std::cerr << "Error: failed to get components version" << std::endl;
		return -1;
	}

	std::cout << "Component \"A\" version: " << componentVersion.data() << std::endl;

	return 0;
}

