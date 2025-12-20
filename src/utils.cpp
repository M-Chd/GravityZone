#include "utils.h"

double gravityForce(double& mass1, double& mass2, double& distance)
{
	if (mass1 > 0 || mass2 > 0) {
		return (G * mass1 * mass2) / pow(distance, 2);
	}
}

bool VectorEquals(Vector2 vector, Vector2 other)
{
	return vector.x == other.x && vector.y == other.y;
}

bool isInside(Vector2 targetPos, Body b)
{
	return distanceBetween(targetPos, b.getPos()) <= b.getRadius();
}

double distanceBetween(Vector2 targetPos, Vector2 other)
{
	return sqrt(pow(other.x - targetPos.x, 2) + pow(other.y - targetPos.y, 2));
}
