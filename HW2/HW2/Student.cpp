#include "Student.h"

Student::Student(std::string name, int age, double weight, int yearStudy, Sex sex)
	: Person(name, age, weight, sex), m_yearStudy(yearStudy)
{
	m_id = Student::s_idGenerator++;
}

int Student::getID() const
{ 
	return m_id;
}

int Student::getYearStudy()
{ 
	return m_yearStudy;
}

void Student::incrementYearStudy()
{
	m_yearStudy++;
}
