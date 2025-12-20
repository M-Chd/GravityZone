#include <iostream>
#include "space.h"
#include "utils.h"

namespace Space {

	space::space() {}

	space::~space() {
		bodies.clear();
	}

	std::vector<Body>& space::getBodies()
	{
		return bodies;
	}

	void space::applyG()
	{
		if (!bodies.empty()) {
			for (auto& b : bodies) {
				//TODO
			}
		}
	}

	void space::updateBodies()
	{
		if (!bodies.empty()) {
			for (auto b : bodies) {
				b.draw();
			}
		}
	}

	void space::freeBodies()
	{
		if (bodies.size() > 10) {
			bodies.clear();
		}
	}

	void space::add(Body b)
	{
		bodies.push_back(b);
	}

	void space::removeAtPos(Vector2 mousePos)
	{
		for (auto it = bodies.begin(); it != bodies.end(); )
		{
			Body b = *it;

			if (isInside(mousePos, b))
			{
				it = bodies.erase(it);
			}
			else
			{
				++it;
			}
		}
	}

}