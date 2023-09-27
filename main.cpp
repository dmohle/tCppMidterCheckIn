#include <iostream>
#include <string>
#include <vector>

class Animal {
public:
    Animal(const std::string& name, const std::string& species)
        : name_(name), species_(species) {
        numOfAnimals++;
    }

    static int numOfAnimals;

    std::string getName() const {
        return name_;
    }

    std::string getSpecies() const {
        return species_;
    }

private:
    std::string name_;
    std::string species_;
};

int Animal::numOfAnimals = 0;

class Hyena : public Animal {
public:
    Hyena(const std::string& name)
        : Animal(name, "Hyena") {}

    static std::vector<std::string> hyenaNames;

    static std::string assignName() {
        if (hyenaNames.empty()) {
            return "No more hyena names available";
        }

        std::string name = hyenaNames.back();
        hyenaNames.pop_back();
        return name;
    }
};

std::vector<std::string> Hyena::hyenaNames = {
    "Shenzi", "Banzai", "Ed", "Zig", "Bud",
    "Lou", "Kamari", "Wema", "Nne", "Madoa",
    "Prince Nevarah"
};

int main() {
    // Creating Animal objects
    Animal lion("Simba", "Lion");
    Animal elephant("Dumbo", "Elephant");

    // Accessing and displaying the number of animals
    std::cout << "Number of animals created: " << Animal::numOfAnimals << std::endl;

    // Creating Hyena objects and assigning names
    for (int i = 0; i < 5; i++) {
        std::cout << "Hyena assigned name: " << Hyena::assignName() << std::endl;
    }

    // Accessing and displaying the remaining number of hyena names
    std::cout << "Remaining hyena names: " << Hyena::hyenaNames.size() << std::endl;

    return 0;
}
