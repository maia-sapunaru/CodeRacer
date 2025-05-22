//
// Created by Maia Sapunaru on 22.05.2025.
//

#ifndef ECONOMICAL_H
#define ECONOMICAL_H
#include "DrivingTechnique.h"


class Economical : public DrivingTechnique {
public:
    void drive(Car& car) const override;
};



#endif //ECONOMICAL_H
