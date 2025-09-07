# Builder Pattern Example in Python

class Car:
    """
    Product class that represents the object we want to build.
    """

    def __init__(self, builder):
        # Assign attributes from the builder instance
        self.engine = builder.engine
        self.wheels = builder.wheels
        self.seats = builder.seats
        self.color = builder.color
        self.sunroof = builder.sunroof
        self.navigation_system = builder.navigation_system

    def __str__(self):
        """
        String representation of the Car object.
        """
        return (f"Car [engine={self.engine}, wheels={self.wheels}, seats={self.seats}, "
                f"color={self.color}, sunroof={self.sunroof}, "
                f"navigation_system={self.navigation_system}]")


class CarBuilder:
    """
    Builder class for constructing Car objects step by step.
    """

    def __init__(self):
        # Default values
        self.engine = None
        self.wheels = 4
        self.seats = 5
        self.color = "Black"
        self.sunroof = False
        self.navigation_system = False

    # Builder methods (fluent interface)
    def set_engine(self, engine):
        self.engine = engine
        return self

    def set_wheels(self, wheels):
        self.wheels = wheels
        return self

    def set_seats(self, seats):
        self.seats = seats
        return self

    def set_color(self, color):
        self.color = color
        return self

    def set_sunroof(self, sunroof):
        self.sunroof = sunroof
        return self

    def set_navigation_system(self, navigation_system):
        self.navigation_system = navigation_system
        return self

    def build(self):
        """
        Build method returns a fully constructed Car object.
        """
        return Car(self)


# Client code
if __name__ == "__main__":
    print("Builder Pattern in Python")

    # First Car
    car1 = (CarBuilder()
            .set_engine("V8")
            .set_color("Red")
            .set_seats(5)
            .set_sunroof(True)
            .build())
    print(car1)

    # Second Car
    car2 = (CarBuilder()
            .set_engine("V6")
            .set_color("Blue")
            .set_seats(4)
            .build())  # Sunroof and navigation are defaults
    print(car2)
