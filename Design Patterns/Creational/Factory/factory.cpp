#include <bits/stdc++.h>
using namespace std;

///////////////////////////////////////////
// Product Interface: Shape
///////////////////////////////////////////

/*
 * Shape:
 * Abstract base class representing the product.
 * Defines the interface for all concrete shape objects.
 */
class Shape
{
public:
  virtual void draw() = 0; // Pure virtual method
  virtual ~Shape() = default;
};

///////////////////////////////////////////
// Concrete Products: Shapes
///////////////////////////////////////////

/*
 * Rectangle:
 * Concrete implementation of Shape.
 */
class Rectangle : public Shape
{
public:
  void draw() override
  {
    cout << "Rectangle" << endl;
  }
};

/*
 * Square:
 * Concrete implementation of Shape.
 */
class Square : public Shape
{
public:
  void draw() override
  {
    cout << "Square" << endl;
  }
};

/*
 * Circle:
 * Concrete implementation of Shape.
 */
class Circle : public Shape
{
public:
  void draw() override
  {
    cout << "Circle" << endl;
  }
};

///////////////////////////////////////////
// Factory Class: ShapeFactory
///////////////////////////////////////////

/*
 * ShapeFactory:
 * Responsible for creating instances of concrete shapes.
 * The client requests an object by type name (string).
 */
class ShapeFactory
{
public:
  Shape *getShape(const string &shapeType)
  {
    if (shapeType == "Rectangle")
    {
      return new Rectangle();
    }
    else if (shapeType == "Square")
    {
      return new Square();
    }
    else if (shapeType == "Circle")
    {
      return new Circle();
    }
    else
    {
      return nullptr;
    }
  }
};

///////////////////////////////////////////
// Main Function: Demonstration
///////////////////////////////////////////

/*
 * Demonstrates the Factory Design Pattern.
 * The factory creates different shape objects based on input.
 */
int main()
{
  cout << "Factory Pattern" << endl;

  // Create factory instance
  ShapeFactory *shapeFactory = new ShapeFactory();

  // Request different shapes from the factory
  Shape *shape1 = shapeFactory->getShape("Circle");
  shape1->draw(); // Output: Circle

  Shape *shape2 = shapeFactory->getShape("Rectangle");
  shape2->draw(); // Output: Rectangle

  Shape *shape3 = shapeFactory->getShape("Square");
  shape3->draw(); // Output: Square

  // Cleanup
  delete shape1;
  delete shape2;
  delete shape3;
  delete shapeFactory;

  return 0;
}
