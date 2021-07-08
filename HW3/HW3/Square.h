#pragma once

#include "Parallelogram.h"

class Square : public Parallelogram
{
public:
	void area() override;
	~Square() override;
};

