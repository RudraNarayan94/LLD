from abc import ABC, abstractmethod

#########################################
# Strategy Interface
#########################################

class DriveStrategy(ABC):
    @abstractmethod
    def drive(self):
        pass

#########################################
# Concrete Strategies
#########################################

class NormalDriveStrategy(DriveStrategy):
    def drive(self):
        print("Normal drive capability")

class SportsDriveStrategy(DriveStrategy):
    def drive(self):
        print("Sports drive capability")

class XYZDriveStrategy(DriveStrategy):
    def drive(self):
        print("XYZ drive capability")

#########################################
# Vehicle Base Class (Context)
#########################################

class Vehicle:
    def __init__(self, drive_strategy: DriveStrategy):
        self.drive_strategy = drive_strategy  # Strategy injection

    def drive(self):
        self.drive_strategy.drive()

#########################################
# Concrete Vehicle Types
#########################################

class SportyVehicle(Vehicle):
    def __init__(self):
        super().__init__(SportsDriveStrategy())

class PassengerVehicle(Vehicle):
    def __init__(self):
        super().__init__(NormalDriveStrategy())

class OffRoadVehicle(Vehicle):
    def __init__(self):
        super().__init__(XYZDriveStrategy())

#########################################
# Main Function
#########################################

if __name__ == "__main__":
    vehicle = SportyVehicle()
    vehicle.drive()
