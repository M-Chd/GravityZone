#pragma once
#include <vector>
#include "body.h"

namespace Space {

	class Space {
	public:

		Space();
		~Space();

		void applyG();

		std::vector<Body> getBodies() const;


	private:
		std::vector<Body> bodies;
	};
}