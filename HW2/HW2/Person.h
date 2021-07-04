#pragma once
#include <iostream>
#include <string>
#include <cstdint>

enum Sex
{
	MALE = 'M',
	FEMALE = 'F',
};

class Person
{
private:
	std::string m_name;
	int m_age;
	double m_weight;
	Sex m_sex;
public:
	Person(std::string name = "", int age = 0, double weight = 0.0, Sex sex = MALE);
	
	std::string getName();
	int getAge();
	double getWeight();

	void setAge(int age);
	void setWeight(double weight);
};

