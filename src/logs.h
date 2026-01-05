#pragma once
#include "logsEvents.h"

class Log {
private:
	logsEvents m_evenType;

public:
	Log() {};
	~Log() {};

	void ErrorMessage(logsEvents event);
	void WarningMessage(logsEvents event);
	void PlaceEvent(logsEvents event);
	void DeleteEvent(logsEvents event);
	void CollisionEvent(logsEvents event);

};