#include "Person.h"

Person::Person(std::string name, int age, double weight, Sex sex)
	: m_name(name),
	m_age(age),
	m_weight(weight),
	m_sex(sex)
{
	
}

std::string Person::getName()
{
	return m_name;
}

int Person::getAge()
{
	return m_age;
}

double Person::getWeight()
{
	return m_weight;
}

void Person::setAge(int age)
{
	m_age = age;
}

void Person::setWeight(double weight)
{
	m_weight = weight;
}