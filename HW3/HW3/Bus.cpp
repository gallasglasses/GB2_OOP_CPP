#include "Bus.h"

Bus::Bus(std::string company, std::string model)
	: Car(company, model)
{
	std::cout << "Bus\nCompany : " << company << "\nModel : " << model << "\n" << std::endl;
}