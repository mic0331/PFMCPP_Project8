#include "SemiTruck.h"

#include <iostream>

SemiTruck::SemiTruck(const std::string& name) : Vehicle(name) {}
SemiTruck::~SemiTruck() = default;
SemiTruck::SemiTruck(const SemiTruck&) = default;

void SemiTruck::closeWindows()
{
    setSpeed(120);
    std::cout << name << ": Truck closing the windows!" << std::endl;
}

void SemiTruck::pullOver()
{
    setSpeed(0);
    std::cout << name << ": hello officer, what seems to be the problem with my truck?" << std::endl;
}
