//
// Created by Maia Sapunaru on 22.05.2025.
//

#include "../include/Enduro.h"

Enduro::Enduro(const std::string& name, const float& speed, const float& fuel, const int& power) : Car(name, speed, fuel, power) {}

float Enduro::getScore() const {
  return speed * 0.9f + fuel * 0.6f;
}