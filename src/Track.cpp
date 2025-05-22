//
// Created by Maia Sapunaru on 22.05.2025.
//

#include "Track.h"
#include<iostream>

Track::Track(const std::string& type, float difficulty, int nrCurves, const std::string& weather) :
 surface(type), difficulty(difficulty), nrCurves(nrCurves), weather(weather) {}

Track::~Track() {}

float Track::getDifficulty() const { return difficulty; }
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
  observers.push_back(observer);
}
void Track::notifyObservers() {
  for (auto* observer : observers) observer->trackUpdate(*this);
}

void Track::setWeather(const std::string& weather) {
  this->weather = weather;
  notifyObservers();
}

void Track::setNrCurves(int nrCurves) {
  this->nrCurves = nrCurves;
  notifyObservers();
}
