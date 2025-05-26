//
// Created by Maia Sapunaru on 22.05.2025.
//

#include "../include/Aggressive.h"

void Aggressive::drive(Car& car) const{
  car.accelerate(15 + car.getPower() * 0.05);
  car.consumeFuel(10);
}