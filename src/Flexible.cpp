//
// Created by Maia Sapunaru on 22.05.2025.
//

#include "../include/Flexible.h"

void Flexible::updateFromTrack(const Track& track) {
    if(track.getWeather() == "rainy" || track.getDifficulty() > 10)
      mode = "economical";
    else if(track.getWeather() == "sunny" || track.getDifficulty() > 1.2)
      mode = "aggresive";
    else
      mode = "balanced";
}

void Flexible::drive(Car& car) const {
    if(mode == "aggresive") {
      car.accelerate(14);
      car.consumeFuel(9);
    }
    else if(mode == "economical") {
      car.accelerate(6);
      car.consumeFuel(3);
    }
    else {
      car.accelerate(10);
      car.consumeFuel(5);
    }
}