//
// Created by Maia Sapunaru on 22.05.2025.
//

#include "Aggressive.h"

void Aggressive::drive(Car& car) const{
  car.accelerate(15);
  car.consumeFuel(10);
}