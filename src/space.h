#pragma once
#include <vector>
#include <numeric>
#include "body.h"
#include "utils.h"

class Body;

class space {
public:

	space();
	~space();

	void applyG();
	void drawBodies();
	void clearBodiesIfOver10();
	void updateAll(float dt);

	void add(Body b);
	void removeAtPos(Vector2 pos);

	std::vector<Body>& getBodies();


private:
	std::vector<Body> bodies;
};