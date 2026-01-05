#include "utils.h"

bool VectorEquals(Vector2 vector, Vector2 other)
{
	return vector.x == other.x && vector.y == other.y;
}

bool isInside(Vector2 targetPos, Body& b)
{
	return distanceBetween(targetPos, b.getPos()) <= b.getRadius();
}

double distanceBetween(Vector2 targetPos, Vector2 other)
{
	return sqrt(pow(other.x - targetPos.x, 2) + pow(other.y - targetPos.y, 2));
}
