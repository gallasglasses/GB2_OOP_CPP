#pragma once

#include "Person.h"

#include <iostream>
#include <string>
#include <cstdint>


class Student : public Person
{
private:
	int m_yearStudy;
	int m_id;

public:
	static int s_idGenerator;
	Student(std::string name = "", int age = 0, double weight = 0.0, int yearStudy = 0, Sex sex = MALE);
	
	int getID() const;
	int getYearStudy() const;
	void incrementYearStudy();
};

