import copy

###############################################
# Prototype Class: Character
###############################################

class Character:
    def __init__(self, name: str, health: int, attack_power: int, level: int):
        self.name = name
        self.health = health
        self.attack_power = attack_power
        self.level = level

    def clone(self):
        """
        Clone method (Prototype Pattern).
        Uses shallow copy since attributes are primitive types.
        """
        return copy.copy(self)

    def show_character_info(self):
        """
        Display character details.
        """
        print(f"Character [Name={self.name}, Health={self.health}, "
              f"AttackPower={self.attack_power}, Level={self.level}]")

###############################################
# Factory using Prototype
###############################################

class CharacterFactory:
    def __init__(self):
        # Prototype character with default attributes
        self.prototype_character = Character("DefaultName", 100, 50, 1)

    def create_character_with_new_name(self, name: str) -> Character:
        cloned = self.prototype_character.clone()
        cloned.name = name
        return cloned

    def create_character_with_new_level(self, level: int) -> Character:
        cloned = self.prototype_character.clone()
        cloned.level = level
        return cloned

    def create_character_with_new_attack_power(self, attack_power: int) -> Character:
        cloned = self.prototype_character.clone()
        cloned.attack_power = attack_power
        return cloned

###############################################
# Client Code
###############################################

if __name__ == "__main__":
    print("Prototype Pattern in Python")

    factory = CharacterFactory()

    # Create a character with a new name
    hero = factory.create_character_with_new_name("Hero")
    hero.show_character_info()

    # Create another character with a new level
    boss = factory.create_character_with_new_level(10)
    boss.show_character_info()

    # Create another character with a new attack power
    warrior = factory.create_character_with_new_attack_power(80)
    warrior.show_character_info()
