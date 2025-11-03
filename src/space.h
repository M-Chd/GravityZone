#pragma once
#include <vector>
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

		logsEvents add(Body* b);

		std::vector<Body*>& getBodies();


	private:
		std::vector<Body*> bodies;
	};
}