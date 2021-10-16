#pragma once
#include "Vehicle.h"

struct SemiTruck : public Vehicle
{
    SemiTruck(const std::string&);
    ~SemiTruck() override;
    SemiTruck(const SemiTruck&);
    
    void closeWindows();

    void pullOver();
};
