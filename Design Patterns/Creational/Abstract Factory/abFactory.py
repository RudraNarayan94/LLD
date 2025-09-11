from abc import ABC, abstractmethod

###########################################
# Product Interface: Vehicle
###########################################

class Vehicle(ABC):
    @abstractmethod
    def drive(self):
        pass

###########################################
# Concrete Products
###########################################

class Car(Vehicle):
    def drive(self):
        print("Car")

class Bike(Vehicle):
    def drive(self):
        print("Bike")

###########################################
# Factory Interface: VehicleFactoryI
###########################################

class VehicleFactoryI(ABC):
    @abstractmethod
    def create_vehicle(self) -> Vehicle:
        pass

###########################################
# Concrete Factories
###########################################

class CarFactory(VehicleFactoryI):
    def create_vehicle(self) -> Vehicle:
        return Car()

class BikeFactory(VehicleFactoryI):
    def create_vehicle(self) -> Vehicle:
        return Bike()

###########################################
# Abstract Factory Producer
###########################################

class VehicleFactoryII:
    @staticmethod
    def get_factory(vehicle_type: str) -> VehicleFactoryI | None:
        vehicle_type = vehicle_type.lower()
        if vehicle_type == "car":
            return CarFactory()
        elif vehicle_type == "bike":
            return BikeFactory()
        else:
            return None

###########################################
# Main Function: Demonstration
###########################################

if __name__ == "__main__":
    print("Abstract Factory Pattern")

    # Get a Car factory and create a Car
    car_factory = VehicleFactoryII.get_factory("Car")
    car = car_factory.create_vehicle()
    car.drive()  # Output: Car

    # Get a Bike factory and create a Bike
    bike_factory = VehicleFactoryII.get_factory("Bike")
    bike = bike_factory.create_vehicle()
    bike.drive()  # Output: Bike
