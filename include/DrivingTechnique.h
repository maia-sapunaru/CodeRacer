//
// Created by Maia Sapunaru on 22.05.2025.
//

#ifndef DRIVINGTECHNIQUE_H
#define DRIVINGTECHNIQUE_H
#include "Car.h"

//clasa abstracta
class DrivingTechnique {
public:
    virtual void drive(Car& car) const = 0;
    virtual ~DrivingTechnique() {}
};

#endif //DRIVINGTECHNIQUE_H
