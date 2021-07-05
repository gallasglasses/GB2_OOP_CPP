#include "Person.h"

Person::Person(std::string name, int age, double weight, Sex sex)
	: m_name(name),
	m_age(age),
	m_weight(weight),
	m_sex(sex)
{
	
}

std::string Person::getName() const
{
	return m_name;
}

int Person::getAge() const
{
	return m_age;
}

double Person::getWeight() const
{
	return m_weight;
}

Sex Person::getSex() const
{
	return m_sex;
}

void Person::setAge(int age)
{
	m_age = age;
}

void Person::setWeight(double weight)
{
	m_weight = weight;
}