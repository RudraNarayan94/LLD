#include <bits/stdc++.h>
using namespace std;

///////////////////////////////////////////
// Product Interface: Vehicle
///////////////////////////////////////////

/*
 * Vehicle:
 * Abstract base class defining the vehicle interface.
 */
class Vehicle
{
public:
  virtual void drive() = 0;
  virtual ~Vehicle() = default;
};

///////////////////////////////////////////
// Concrete Products
///////////////////////////////////////////

/*
 * Car:
 * Concrete implementation of Vehicle.
 */
class Car : public Vehicle
{
public:
  void drive() override
  {
    cout << "Car" << endl;
  }
};

/*
 * Bike:
 * Concrete implementation of Vehicle.
 */
class Bike : public Vehicle
{
public:
  void drive() override
  {
    cout << "Bike" << endl;
  }
};

///////////////////////////////////////////
// Factory Interface: VehicleFactoryI
///////////////////////////////////////////

/*
 * VehicleFactoryI:
 * Abstract factory interface for creating vehicles.
 */
class VehicleFactoryI
{
public:
  virtual Vehicle *createVehicle() = 0;
  virtual ~VehicleFactoryI() = default;
};

///////////////////////////////////////////
// Concrete Factories
///////////////////////////////////////////

/*
 * CarFactory:
 * Produces Car objects.
 */
class CarFactory : public VehicleFactoryI
{
public:
  Vehicle *createVehicle() override
  {
    return new Car();
  }
};

/*
 * BikeFactory:
 * Produces Bike objects.
 */
class BikeFactory : public VehicleFactoryI
{
public:
  Vehicle *createVehicle() override
  {
    return new Bike();
  }
};

///////////////////////////////////////////
// Abstract Factory Producer
///////////////////////////////////////////

/*
 * VehicleFactoryII:
 * Factory producer that returns a specific factory
 * based on input (CarFactory or BikeFactory).
 */
class VehicleFactoryII
{
public:
  static VehicleFactoryI *getFactory(const string &vehicleType)
  {
    if (vehicleType == "Car")
      return new CarFactory();
    else if (vehicleType == "Bike")
      return new BikeFactory();
    else
      return nullptr;
  }
};

///////////////////////////////////////////
// Main Function: Demonstration
///////////////////////////////////////////

int main()
{
  cout << "Abstract Factory Pattern" << endl;

  // Get car factory from abstract factory
  VehicleFactoryI *carFactory = VehicleFactoryII::getFactory("Car");
  Vehicle *car = carFactory->createVehicle();
  car->drive(); // Output: Car

  // Get bike factory from abstract factory
  VehicleFactoryI *bikeFactory = VehicleFactoryII::getFactory("Bike");
  Vehicle *bike = bikeFactory->createVehicle();
  bike->drive(); // Output: Bike

  // Cleanup
  delete car;
  delete carFactory;
  delete bike;
  delete bikeFactory;

  return 0;
}
