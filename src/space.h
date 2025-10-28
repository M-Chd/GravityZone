#pragma once
#include <vector>
#include "body.h"

namespace Space {

	class space {
	public:

		space();
		~space();

		void applyG();
		void updateBodies();
		void freeBodies();

		void add(Body* b);

		std::vector<Body*>& getBodies();


	private:
		std::vector<Body*> bodies;
	};
}