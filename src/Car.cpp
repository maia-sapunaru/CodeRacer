//
// Created by Maia Sapunaru on 22.05.2025.
//

#include "../include/Car.h"

int Car::carNumber = 0;
float Car::totalDistance = 0;

Car::Car(const std::string& name, float fuel) : name(name), speed(0), fuel(fuel) {
    carNumber++;
}
Car::~Car() {}

float Car::getTotalDistance() {
    return totalDistance;
}

void Car::addDistance(float km) {
    totalDistance += km;
}


int Car::getCarNumber() {
    return carNumber;
}





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

const std::string& Car::getName() const { return name; }
float Car::getSpeed() const { return speed; }
float Car::getFuel() const { return fuel; }

std::ostream& operator << (std::ostream& out, const Car& car) {
  car.display(out);
  return out;
}

