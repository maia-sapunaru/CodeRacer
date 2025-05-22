//
// Created by Maia Sapunaru on 22.05.2025.
//

#include "Car.h"

Car::Car(const std::string& name, float fuel) : name(name), speed(0), fuel(fuel) {}
Car::~Car() {}

void Car::accelerate(float amount) {
    speed += amount;
    consumeFuel(amount * 0.5f);
}

void Car::consumeFuel(float amount) {
    fuel -= amount;
    if (fuel <= 0) fuel = 0;
}

void Car::display(std::ostream& out) const {
    out << "Car: " << name << " " << " Spped: " << speed << " fuel: " << fuel;
}

const std::string& Vechicle::getName() const { return name; }
float Car::getSpeed() const { return speed; }
float Car::getFuel() const { return fuel; }

std::ostream& operator << (std::ostream& out, const Car& vehicle) {
  vehicle.display(out);
  return out;
}

