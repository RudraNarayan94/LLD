#include <bits/stdc++.h>
using namespace std;

///////////////////////////////////////////
// Component Interface: BasePizza
///////////////////////////////////////////

/*
 * BasePizza:
 * Abstract base class that defines the interface for pizzas.
 * All concrete pizzas and decorators must inherit from this.
 */
class BasePizza
{
public:
  virtual int cost() = 0;
  virtual ~BasePizza() = default;
};

///////////////////////////////////////////
// Concrete Components: Pizza Variants
///////////////////////////////////////////

/*
 * FarmHouse:
 * A concrete pizza with a fixed base cost.
 */
class FarmHouse : public BasePizza
{
public:
  int cost() override
  {
    return 200;
  }
};

/*
 * Margherita:
 * A simple pizza with a lower cost.
 */
class Margherita : public BasePizza
{
public:
  int cost() override
  {
    return 100;
  }
};

/*
 * VegDelight:
 * Another pizza variant with moderate cost.
 */
class VegDelight : public BasePizza
{
public:
  int cost() override
  {
    return 120;
  }
};

///////////////////////////////////////////
// Decorator Base Class: ToppingDecorator
///////////////////////////////////////////

/*
 * ToppingDecorator:
 * Abstract decorator that also inherits from BasePizza.
 * It wraps a BasePizza pointer to allow toppings to be added dynamically.
 */
class ToppingDecorator : public BasePizza
{
protected:
  BasePizza *basePizza;

public:
  // Constructor injection of the base pizza
  ToppingDecorator(BasePizza *basePizza)
  {
    this->basePizza = basePizza;
  }

  // Virtual destructor to ensure proper cleanup
  virtual ~ToppingDecorator()
  {
    delete basePizza;
  }
};

///////////////////////////////////////////
// Concrete Decorators: Toppings
///////////////////////////////////////////

/*
 * FreshTomato:
 * Adds tomato topping with additional cost.
 */
class FreshTomato : public ToppingDecorator
{
public:
  FreshTomato(BasePizza *basePizza) : ToppingDecorator(basePizza) {}

  int cost() override
  {
    return this->basePizza->cost() + 20;
  }
};

/*
 * ExtraCheese:
 * Adds extra cheese topping.
 */
class ExtraCheese : public ToppingDecorator
{
public:
  ExtraCheese(BasePizza *basePizza) : ToppingDecorator(basePizza) {}

  int cost() override
  {
    return this->basePizza->cost() + 30;
  }
};

/*
 * Mushroom:
 * Adds mushroom topping.
 */
class Mushroom : public ToppingDecorator
{
public:
  Mushroom(BasePizza *basePizza) : ToppingDecorator(basePizza) {}

  int cost() override
  {
    return this->basePizza->cost() + 40;
  }
};

///////////////////////////////////////////
// Main Function: Demonstration
///////////////////////////////////////////

/*
 * Demonstrates the use of the Decorator Pattern.
 * Multiple toppings can be dynamically added to a pizza.
 */
int main()
{
  cout << "Decorator Pattern" << endl;

  // Create base pizza
  BasePizza *basePizza = new FarmHouse();

  // Add toppings dynamically
  basePizza = new ExtraCheese(basePizza);
  basePizza = new Mushroom(basePizza);
  basePizza = new FreshTomato(basePizza);

  // Final cost after decorating
  cout << "Total cost: " << basePizza->cost() << endl;

  // Clean up memory
  delete basePizza;

  return 0;
}
