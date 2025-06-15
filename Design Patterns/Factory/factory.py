from abc import ABC, abstractmethod

###########################################
# Product Interface: Shape
###########################################

class Shape(ABC):
    @abstractmethod
    def draw(self):
        pass

###########################################
# Concrete Products: Shapes
###########################################

class Rectangle(Shape):
    def draw(self):
        print("Rectangle")

class Square(Shape):
    def draw(self):
        print("Square")

class Circle(Shape):
    def draw(self):
        print("Circle")

###########################################
# Factory Class: ShapeFactory
###########################################

class ShapeFactory:
    def get_shape(self, shape_type: str) -> Shape | None:
        shape_type = shape_type.lower()
        if shape_type == "rectangle":
            return Rectangle()
        elif shape_type == "square":
            return Square()
        elif shape_type == "circle":
            return Circle()
        else:
            return None

###########################################
# Main Function: Demonstration
###########################################

if __name__ == "__main__":
    print("Factory Pattern")

    shape_factory = ShapeFactory()

    shape1 = shape_factory.get_shape("Circle")
    shape1.draw()  # Output: Circle

    shape2 = shape_factory.get_shape("Rectangle")
    shape2.draw()  # Output: Rectangle

    shape3 = shape_factory.get_shape("Square")
    shape3.draw()  # Output: Square
