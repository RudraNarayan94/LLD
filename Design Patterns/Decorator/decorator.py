from abc import ABC, abstractmethod

###########################################
# Component Interface: BasePizza
###########################################

class BasePizza(ABC):
    @abstractmethod
    def cost(self) -> int:
        pass

###########################################
# Concrete Components: Pizza Variants
###########################################

class FarmHouse(BasePizza):
    def cost(self) -> int:
        return 200

class Margherita(BasePizza):
    def cost(self) -> int:
        return 100

class VegDelight(BasePizza):
    def cost(self) -> int:
        return 120

###########################################
# Decorator Base Class: ToppingDecorator
###########################################

class ToppingDecorator(BasePizza):
    def __init__(self, base_pizza: BasePizza):
        self.base_pizza = base_pizza

###########################################
# Concrete Decorators: Toppings
###########################################

class FreshTomato(ToppingDecorator):
    def cost(self) -> int:
        return self.base_pizza.cost() + 20

class ExtraCheese(ToppingDecorator):
    def cost(self) -> int:
        return self.base_pizza.cost() + 30

class Mushroom(ToppingDecorator):
    def cost(self) -> int:
        return self.base_pizza.cost() + 40

###########################################
# Main Function: Demonstration
###########################################

if __name__ == "__main__":
    print("Decorator Pattern")

    # Create base pizza
    base_pizza = FarmHouse()

    # Decorate with toppings
    base_pizza = ExtraCheese(base_pizza)
    base_pizza = Mushroom(base_pizza)
    base_pizza = FreshTomato(base_pizza)

    # Final cost
    print(f"Total cost: {base_pizza.cost()}")
