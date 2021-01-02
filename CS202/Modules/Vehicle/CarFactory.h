#pragma once

#include "VehicleInterface.h"
#include "Car.h"

enum class VehicleCateglory
{
	car,
	last
};

class CarFactory
{
public:
	static VehicleInterface* getRandom() {
		VehicleCateglory type = static_cast<VehicleCateglory>(rand() % static_cast<int>(VehicleCateglory::last));

		switch(type) {
		case VehicleCateglory::car:
			return new Car();
		default:
			throw "Undefined vehicle";
		}
	}
};