//
// Created by Maia Sapunaru on 22.05.2025.
//

#include "SportsCar.h"

SportsCar::SportsCar(const std::string& name) : Car(name, 100) {}

float SportsCar::getScore() const {
    return speed * 1.2f + fuel * 0.3f;
}