//
// Created by Maia Sapunaru on 22.05.2025.
//

#include "Economical.h"

void Economical::drive(Car& car) const {
    car.accelerate(5);
    car.consumeFuel(2);
}