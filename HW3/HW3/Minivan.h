#pragma once
#include "Bus.h"
#include "PassengerCar.h"

class Minivan : public PassengerCar, public Bus
{
public:
	Minivan(std::string company, std::string model);
};

