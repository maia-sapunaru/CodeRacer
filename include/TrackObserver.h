//
// Created by Maia Sapunaru on 22.05.2025.
//

#ifndef TRACKOBSERVER_H
#define TRACKOBSERVER_H
#include "../include/Track.h"
class Track;

class TrackObserver {
public:
    virtual void trackUpdate(const Track& track) = 0;
    virtual ~TrackObserver() {}
};



#endif //TRACKOBSERVER_H