#pragma once

#include "Parallelogram.h"

class Rectangle : public Parallelogram
{
public:
	void area() override;
	~Rectangle() override;
};

