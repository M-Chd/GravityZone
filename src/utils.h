#pragma once
#include "constant.h"
#include "body.h"
#include <raylib.h>
#include <math.h>

using namespace Space;

double gravityForce(double& mass1, double& mass2, double& distance);
bool VectorEquals(Vector2 v1, Vector2 v2);
bool isInside(Vector2 targetPos, Body b);
double distanceBetween(Vector2 targetPos, Vector2 other);