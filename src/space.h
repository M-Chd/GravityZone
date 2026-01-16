#pragma once
#include <vector>
#include <numeric>
#include "body.h"
#include "utils.h"
#include "logs.h"
#include "LogEvents.h"

class Log;

class space {
public:

	space();
	~space();

	void applyG();
	void drawBodies();
	void clearBodiesIfOver10(Log& log);
	void updateAll(float dt,Log& log);

	void add(Body b,Log& log);
	void removeAtPos(Vector2 pos,Log& log);

	std::vector<Body>& getBodies();
	std::vector<logsEvents>& getLogs() { return logs;}

	void notify(Log& log);



private:
	std::vector<logsEvents> logs;
	std::vector<Body> bodies;
};