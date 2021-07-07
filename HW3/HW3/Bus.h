#pragma once
#include "Car.h"

class Bus : virtual public Car
{
public: 
	Bus(std::string company, std::string model);
};

