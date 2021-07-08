#include "Minivan.h"

Minivan::Minivan(std::string company, std::string model)
	: PassengerCar(company, model), Bus(company, model), Car(company, model)
{
	std::cout << "Minivan\nCompany : " << company << "\nModel : " << model << "\n" << std::endl;
}