//
// Created by Maia Sapunaru on 22.05.2025.
//

#include "../include/TunedSportsCar.h"

TunedSportsCar::TunedSportsCar(const std::string& name, const float& speed, const float& fuel, const int& power) : SportsCar(name, speed, fuel, power) {
    accelerate(10);
}

float TunedSportsCar::getScore() const {
    return speed * 1.5f + fuel * 0.2f;
}