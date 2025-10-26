#include <iostream>
#include "space.h"

namespace Space {

	Space::Space()
	{
	}

	Space::~Space()
	{
	}

	std::vector<Body> Space::getBodies() const
	{
		return bodies;
	}

	void Space::applyG()
	{
		for (auto& b : bodies) {

		}
	}

}