//
// Created by Maia Sapunaru on 22.05.2025.
//

#include "Enduro.h"

Enduro::Enduro(const std::string& name) : Car(name, 130) {}

float Enduro::getScore() const {
  return speed * 0.9f + fuel * 0.6f;
}