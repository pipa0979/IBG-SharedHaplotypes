/*
 * Flags.cpp
 *
 *  Created on: Mar 30, 2016
 *      Author: root
 */
#include "Flags.hpp"

void Flags::setMIN_BP_DISTANCE(unsigned long int min_bp_distance)
{
	MIN_BP_DISTANCE = min_bp_distance;
}

unsigned long int Flags::getMIN_BP_DISTANCE()
{
	return  MIN_BP_DISTANCE;
}


