#include <iostream>
#include "handleEvent.h"

namespace Space {
	void handleEvent(space& Space)
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			auto mousePos = GetMousePosition();

			Body* planet = new Body(WHITE, mousePos, 50, 1, Velocity2(1,1));

			Space.add(planet);
		}
	}
	//TODO Need to be moved and optimized.
}