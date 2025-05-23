//
// Created by Maia Sapunaru on 22.05.2025.
//

#include "../include/SUV.h"

SUV::SUV(const std::string& name) : Car(name, 130) {}

float SUV::getScore() const {
    return speed * 1.0f + fuel * 0.4f;
}
