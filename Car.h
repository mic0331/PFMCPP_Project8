#pragma once
#include "Vehicle.h"

struct Car : Vehicle
{
    Car(const std::string&);
    void closeWindows();

    void tryToEvade();
};
