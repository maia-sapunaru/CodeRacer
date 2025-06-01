//
// Created by Maia Sapunaru on 22.05.2025.
//

#include "../include/Car.h"
#include "../include/Overheated.h"

int Car::carNumber = 0;
float Car::totalDistance = 0;

Car::Car() : name(""), speed(0), fuel(0), power(0) {
    carNumber++;
}
Car::Car(const std::string& name, float speed, float fuel, int power) : name(name), speed(speed), fuel(fuel), power(power) {
    carNumber++;
}
Car::~Car() {
    carNumber--;
}

Car& Car::operator=(const Car& rhs) {
    name = rhs.name;
    speed = rhs.speed;
    fuel = rhs.fuel;
    power = rhs.power;
    return *this;
}

/*
float Car::getTotalDistance() {
    return totalDistance;
}
*/


/*
void Car::addDistance(float km) {
    totalDistance += km;
}
*/



int Car::getCarNumber() {
    return carNumber;
}


int Car::getPower() const {
    return power;
}


/*
float Car::getFuel() const{
    return fuel;
}
*/
float Car::getSpeed() const {
    return speed;
}



void Car::setName(const std::string nam) {
     name = nam;
}

void Car:: setSpeed(float sp) {
    speed = sp;
}

void Car::setFuel(float f) {
    fuel = f;
}

void Car::setPower(int p) {
    power = p;
}


void Car::accelerate(float amount) {
    if (speed > 1000.0f) {
        throw Overheated("Motor supraincalzit! Trebuie sa incetiniti sau masina va face boom!");
    }
    speed += amount;
    consumeFuel(amount * 0.5f);
}

void Car::consumeFuel(float amount) {
    fuel -= amount;
    if (fuel <= 0) fuel = 0;
}

void Car::display(std::ostream& out) const {
    out << "Car: " << name  << " Id: " << getCarNumber() << " Speed: " << speed << " Fuel: " << fuel << " Power" << power;
}

const std::string& Car::getName() const { return name; }

bool Car::finishedFuel() const {
    return fuel <= 0;
}

void Car::resetScore() {
    score = 0;
}


float Car::getMaxSpeed() const {
    return 100 * 0.3f * fuel + 0.6f * power;
}

bool Car::isOverHeated() const {
    return overheated;
}

void Car::setOverheated(bool ch) {
    overheated = ch;
}

std::istream& operator>> (std::istream& in, Car& car) {
    std::string name;
    float speed, fuel;
    int power;
    in >> name >> speed >> fuel >> power;
    car.setName(name);
    car.setSpeed(speed);
    car.setFuel(fuel);
    car.setPower(power);
    return in;
}
std::ostream& operator << (std::ostream& out, const Car& car) {
  car.display(out);
  return out;
}

