#include <bits/stdc++.h>
using namespace std;

// Product Class
class Car
{
private:
  string engine;
  int wheels;
  int seats;
  string color;
  bool sunroof;
  bool navigationSystem;

  // Private constructor: Only Builder can create Car objects
  Car(const string &engine, int wheels, int seats, const string &color,
      bool sunroof, bool navigationSystem)
      : engine(engine), wheels(wheels), seats(seats),
        color(color), sunroof(sunroof), navigationSystem(navigationSystem) {}

public:
  // Friend Builder class
  class CarBuilder;

  // Getter methods
  string getEngine() const { return engine; }
  int getWheels() const { return wheels; }
  int getSeats() const { return seats; }
  string getColor() const { return color; }
  bool hasSunroof() const { return sunroof; }
  bool hasNavigationSystem() const { return navigationSystem; }

  // toString equivalent
  string toString() const
  {
    stringstream ss;
    ss << "Car [engine=" << engine
       << ", wheels=" << wheels
       << ", seats=" << seats
       << ", color=" << color
       << ", sunroof=" << (sunroof ? "true" : "false")
       << ", navigationSystem=" << (navigationSystem ? "true" : "false")
       << "]";
    return ss.str();
  }
};

// Builder Class
class Car::CarBuilder
{
private:
  string engine;
  int wheels = 4;                // Default value
  int seats = 5;                 // Default value
  string color = "Black";        // Default value
  bool sunroof = false;          // Default value
  bool navigationSystem = false; // Default value

public:
  // Builder methods (return reference for chaining)
  CarBuilder &setEngine(const string &engine)
  {
    this->engine = engine;
    return *this;
  }
  CarBuilder &setWheels(int wheels)
  {
    this->wheels = wheels;
    return *this;
  }
  CarBuilder &setSeats(int seats)
  {
    this->seats = seats;
    return *this;
  }
  CarBuilder &setColor(const string &color)
  {
    this->color = color;
    return *this;
  }
  CarBuilder &setSunroof(bool sunroof)
  {
    this->sunroof = sunroof;
    return *this;
  }
  CarBuilder &setNavigationSystem(bool navigationSystem)
  {
    this->navigationSystem = navigationSystem;
    return *this;
  }

  // Build method
  Car build()
  {
    return Car(engine, wheels, seats, color, sunroof, navigationSystem);
  }
};

// Client Code
int main()
{
  cout << "Builder Pattern Example" << endl;

  // Create a car using the builder
  Car::CarBuilder builder;
  Car car1 = builder.setEngine("V8")
                 .setColor("Red")
                 .setSeats(5)
                 .setSunroof(true)
                 .build();

  cout << car1.toString() << endl;

  // Create another car with different specifications
  Car car2 = builder.setEngine("V6")
                 .setColor("Blue")
                 .setSeats(4)
                 .build(); // Sunroof & Navigation default

  cout << car2.toString() << endl;

  return 0;
}
