//
// Created by Maia Sapunaru on 22.05.2025.
//

#include "../include/SUV.h"

SUV::SUV(const std::string& name, const float& speed, const float& fuel, const int& power) : Car(name, speed, fuel, power) {}

float SUV::getScore() const {
    return speed * 1.0f + fuel * 0.4f;
}
