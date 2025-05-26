//
// Created by Maia Sapunaru on 22.05.2025.
//

#ifndef AGGRESSIVE_H
#define AGGRESSIVE_H
#include "DrivingTechnique.h"


class Aggressive : public DrivingTechnique {
public:
    void drive(Car& car) const override;
};


#endif //AGGRESSIVE_H
