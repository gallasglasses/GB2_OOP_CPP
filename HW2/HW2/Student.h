#pragma once

#include "Person.h"

#include <iostream>
#include <string>
#include <cstdint>


class Student : public Person
{
private:
	int m_yearStudy;
	static int s_idGenerator;
	int m_id;

public:
	
	Student(std::string name = "", int age = 0, double weight = 0.0, int yearStudy = 0, Sex sex = MALE);
	
	//friend std::ostream& operator<< (std::ostream & out, const Student & student);

	int getID() const;
	int getYearStudy();
	void incrementYearStudy();
};

