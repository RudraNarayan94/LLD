#include <iostream>
using namespace std;

///////////////////////////////////////////
// Strategy Interface: DriveStrategy
///////////////////////////////////////////

class DriveStrategy
{
public:
  virtual void drive() = 0; // Pure virtual function
};

///////////////////////////////////////////
// Concrete Strategies
///////////////////////////////////////////

class NormalDriveStrategy : public DriveStrategy
{
public:
  void drive() override
  {
    cout << "Normal drive capability" << endl;
  }
};

class SportsDriveStrategy : public DriveStrategy
{
public:
  void drive() override
  {
    cout << "Sports drive capability" << endl;
  }
};

class XYZDriveStrategy : public DriveStrategy
{
public:
  void drive() override
  {
    cout << "XYZ drive capability" << endl;
  }
};

///////////////////////////////////////////
// Vehicle Base Class (Context)
///////////////////////////////////////////

class Vehicle
{
private:
  DriveStrategy *driveObj; // Strategy object

public:
  // Constructor injection
  Vehicle(DriveStrategy *driveObj)
  {
    this->driveObj = driveObj;
  }

  virtual void drive()
  {
    driveObj->drive();
  }

  // Virtual destructor to avoid memory leaks
  virtual ~Vehicle()
  {
    delete driveObj;
  }
};

///////////////////////////////////////////
// Concrete Vehicle Types
///////////////////////////////////////////

class SportyVehicle : public Vehicle
{
public:
  SportyVehicle() : Vehicle(new SportsDriveStrategy()) {}
};

class PassengerVehicle : public Vehicle
{
public:
  PassengerVehicle() : Vehicle(new NormalDriveStrategy()) {}
};

class OffRoadVehicle : public Vehicle
{
public:
  OffRoadVehicle() : Vehicle(new XYZDriveStrategy()) {}
};

///////////////////////////////////////////
// Main Function
///////////////////////////////////////////

int main()
{
  Vehicle *vehicle = new SportyVehicle();
  vehicle->drive();

  delete vehicle;
  return 0;
}
