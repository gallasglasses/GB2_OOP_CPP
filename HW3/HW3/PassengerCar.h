#pragma once
#include "Car.h"

class PassengerCar : virtual public Car
{
public:
	PassengerCar(std::string company, std::string model);
};

