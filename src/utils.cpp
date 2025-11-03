#include "utils.h"

double gravityForce(double& mass1, double& mass2, double& distance)
{
	if (mass1 > 0 || mass2 > 0) {
		return (G * mass1 * mass2) / pow(distance, 2);
	}
}
