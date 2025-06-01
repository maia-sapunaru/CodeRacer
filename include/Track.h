//
// Created by Maia Sapunaru on 22.05.2025.
//

#ifndef TRACK_H
#define TRACK_H
#include<string>
#include<vector>
#include "../include/TrackObserver.h"
class TrackObserver;

class Track {
private:
    std::vector<TrackObserver*> obs;

protected:
    std::string surface;
    int nrCurves;
    float difficulty;
    std::string weather;
public:
    Track(const std::string& type, int nrCurves, float difficulty, const std::string& weather);
    virtual ~Track();

    float getDifficulty() const;
    int getNrCurves() const;
    const std::string& getWeather() const;
    //const std::string& getSurface() const;

    virtual void display(std::ostream& out) const;

    friend std::ostream& operator << (std::ostream& out, const Track& track);



    void addObserver(TrackObserver* observer);
    void notifyObservers();
    void setWeather(const std::string& weather);
    void setNrCurves(int nrCurves);

    void randomWeather();
};



#endif //TRACK_H
