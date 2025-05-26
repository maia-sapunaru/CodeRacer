//
// Created by Maia Sapunaru on 22.05.2025.
//

#include "SportsCar.h"

SportsCar::SportsCar(const std::string& name, const float& speed, const float& fuel, const int& power) : Car(name, speed, fuel, power) {}

float SportsCar::getScore() const {
    return speed * 1.2f + fuel * 0.3f;
}