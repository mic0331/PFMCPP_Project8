#pragma once
#include "Vehicle.h"

struct Car : public Vehicle
{
    Car(const std::string&);
    void closeWindows();

    void tryToEvade();
};
