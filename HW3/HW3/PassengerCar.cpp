#include "PassengerCar.h"

PassengerCar::PassengerCar(std::string company, std::string model)
	: Car(company, model)
{
	std::cout << "Passenger car\nCompany : " << company << "\nModel : " << model << "\n" << std::endl;
}