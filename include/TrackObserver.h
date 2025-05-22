//
// Created by Maia Sapunaru on 22.05.2025.
//

#ifndef TRACKOBSERVER_H
#define TRACKOBSERVER_H
#include "Track.h"


class TrackObserver {
public:
    virtual void trackUpdate(const Track& track) = 0;
    virtual ~TrackObserver() {};
};



#endif //TRACKOBSERVER_H
