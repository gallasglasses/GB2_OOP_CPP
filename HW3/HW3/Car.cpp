#include "Car.h"

Car::Car(std::string company, std::string model)
{
	std::cout << "Car\nCompany : " << company << "\nModel : " << model << "\n" << std::endl;
}

Car::Car()
{
	std::cout << "Default car\n";
}