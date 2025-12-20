#pragma once
#include <vector>
#include <numeric>
#include "body.h"
#include "logsEvents.h"

namespace Space {

	class space {
	public:

		space();
		~space();

		void applyG();
		void updateBodies();
		void freeBodies();

		void add(Body b);
		void removeAtPos(Vector2 pos);

		std::vector<Body>& getBodies();


	private:
		std::vector<Body> bodies;
	};
}