#pragma once
#include "constant.h"
#include "space.h"
#include <raylib.h>
#include <math.h>

class Body;

bool VectorEquals(Vector2 v1, Vector2 v2);
bool isInside(Vector2 targetPos, Body& b);
double distanceBetween(Vector2 targetPos, Vector2 other);