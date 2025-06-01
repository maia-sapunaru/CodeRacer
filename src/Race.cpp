//
// Created by Maia Sapunaru on 26.05.2025.
//

#include "../include/Race.h"
#include<algorithm>
#include<iostream>


Race::Race(const std::string& name, const std::vector<Car*>& cars) : raceName(name), cars(cars) {
    total = (*std::max_element(cars.begin(), cars.end(), [](const Car*  a, const Car*  b)
    {
          return a->getScore() < b->getScore();
    })) ->getScore();
}

float Race::getScore() const {
  return total;
}

const::std::string& Race::getRaceName() const {
  return raceName;
}


/*
const std::vector<Car*>& Race::getCars() const {
  return cars;
}
*/

std::ostream& operator<<(std::ostream& os, const Race& race) {
  os << "Cursa: " << race.getRaceName() << " | Castigator: " << race.getWinner()->getName() << " ->  Scor castigator: " << race.getScore();
  return os;
}


Car* Race::getWinner() const {
  if (cars.empty()) return nullptr;
  Car* winner = cars[0];
  for (Car* car : cars) {
    if (car->getScore() > winner->getScore()) {
      winner = car;
    }
  }
  return winner;
}
