//
// Created by Maia Sapunaru on 22.05.2025.
//

#ifndef FLEXIBLE_H
#define FLEXIBLE_H
#include "DrivingTechnique.h"
#include "Track.h"


class Flexible : public DrivingTechnique{
private:
    std::string mode;
public:
    void drive(Car& car) const override;
    void updateFromTrack(const Track& track);
};



#endif //FLEXIBLE_H