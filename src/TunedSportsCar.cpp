//
// Created by Maia Sapunaru on 22.05.2025.
//

#include "../include/TunedSportsCar.h"

TunedSportsCar::TunedSportsCar(const std::string& name) : SportsCar(name) {
    accelerate(10);
}

float TunedSportsCar::getScore() const {
    return speed * 1.5f + fuel * 0.2f;
}