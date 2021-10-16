#include "Highway.h"
#include "Car.h"
#include "Motorcycle.h"
#include "SemiTruck.h"

void Highway::changeSpeed(int newSpeed)
{
    speedLimit = newSpeed;
    for( auto* vehicle : vehicles )
    {
        vehicle->setSpeed(speedLimit);
    }
}

void Highway::addVehicleInternal(Vehicle* v)
{
    /*
    depending on the derived type, call the member function that doesn't evade the cops. 
    */
    if( auto* vCar = dynamic_cast<Car*>(v) )
    {
        vCar->closeWindows();
    }
    if( auto* vMotorcycle = dynamic_cast<Motorcycle*>(v) )
    {
        vMotorcycle->lanesplitAndRace();
    }
    if( auto* vSemiTruck = dynamic_cast<SemiTruck*>(v) )
    {
        vSemiTruck->closeWindows();
    }
}

void Highway::removeVehicleInternal(Vehicle* v)
{
    /*
    depending on the derived type, call the member function that tries to evade the cops. 

    trucks pull over, but cars and bikes try to evade!!
    */
    if( auto* vCar = dynamic_cast<Car*>(v) )
    {
        vCar->tryToEvade();
    }
    if( auto* vMotorcycle = dynamic_cast<Motorcycle*>(v) )
    {
        vMotorcycle->tryToEvade();
    }
    if( auto* vSemiTruck = dynamic_cast<SemiTruck*>(v) )
    {
        vSemiTruck->pullOver();
    }
}

void Highway::addVehicle(Vehicle* v)
{
    vehicles.push_back(v);
    addVehicleInternal(v);
}
void Highway::removeVehicle(Vehicle* v)
{
    vehicles.erase(std::remove(vehicles.begin(), 
                               vehicles.end(), 
                               v), 
                   vehicles.end());
    removeVehicleInternal(v);
}
