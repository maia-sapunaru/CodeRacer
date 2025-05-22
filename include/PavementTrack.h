//
// Created by Maia Sapunaru on 22.05.2025.
//

#ifndef PAVEMENTTRACK_H
#define PAVEMENTTRACK_H
#include "Track.h"


class PavementTrack : public Track{
public:
    PavementTrack(int nrCurves, const std::string& weather);
};



#endif //PAVEMENTTRACK_H
