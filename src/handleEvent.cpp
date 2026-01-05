#include <iostream>
#include "handleEvent.h"

void handleEvent(space& Space)
{
	if (IsMouseButtonPressed(MOUSE_BUTTON_LEFT)) {
		Vector2 mousePos = GetMousePosition();
		mousePos = { mousePos.x / scale,mousePos.y / scale };

		Body planet = Body(WHITE, mousePos, 10e12, 1, Vector2(0,0));

		Space.add(planet);
	}

	if (IsMouseButtonDown(MOUSE_BUTTON_RIGHT)) {
		Vector2 mousePos = GetMousePosition();
		mousePos = { mousePos.x / scale, mousePos.y / scale };
			
		Space.removeAtPos(mousePos);
	}
}
	//TODO Need to be moved and optimized.