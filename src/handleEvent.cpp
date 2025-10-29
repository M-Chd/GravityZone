#include <iostream>
#include "handleEvent.h"

namespace Space {
	void handleEvent(space& Space)
	{
		if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
			Vector2 mousePos = GetMousePosition();
			mousePos = { mousePos.x / scale,mousePos.y / scale };

			Body* planet = new Body(WHITE, mousePos, 50, 1, Velocity2(1,1));

			Space.add(planet);
		}
	}
	//TODO Need to be moved and optimized.
}