//
// Created by Maia Sapunaru on 22.05.2025.
//

#include "../include/Track.h"
#include<iostream>
#include<ctime>
#include<cstdlib>

Track::Track(const std::string& type, float difficulty, int nrCurves, const std::string& weather) :
 surface(type), difficulty (getDifficulty()), nrCurves(nrCurves), weather(weather) {

}

Track::~Track() {}

float Track::getDifficulty() const {
  return getNrCurves()%10;
}
int Track::getNrCurves() const { return nrCurves; }
const std::string& Track::getWeather() const { return weather; }
const std::string& Track::getSurface() const { return surface; }

void Track::display(std::ostream& out) const {
    out << "Track: " << surface << " "  << "Difficulty: " << difficulty << " "  << "Weather: " << weather << " " << "Number of curves: " << nrCurves << "\n";
}

std::ostream& operator<<(std::ostream& out, const Track& track) {
    track.display(out);
    return out;
}

void Track::addObserver (TrackObserver* observer) {
  obs.push_back(observer);
}
void Track::notifyObservers() {
  for (TrackObserver* observer : obs) observer->trackUpdate(*this);
}

void Track::setWeather(const std::string& weather) {
  this->weather = weather;
  notifyObservers();
}

void Track::setNrCurves(int nrCurves) {
  this->nrCurves = nrCurves;
  notifyObservers();
}

void Track::randomWeather() {
  int chance = rand() % 100;
  int chance2 = rand() % 2;
  if (chance < 50) {
    std::string newWeather;
    if (weather == "sunny" && chance2 == 0 || weather == "rainy" && chance2 == 0)
      newWeather = "cloudy";
    else if (weather == "sunny" && chance2 == 1 || weather == "cloudy" && chance2 == 0)
      newWeather = "rainy";
    else if (weather == "cloudy" && chance2 == 1 || weather == "rainy" && chance2 == 1)
      newWeather = "sunny";

    setWeather(newWeather);

  }
}
