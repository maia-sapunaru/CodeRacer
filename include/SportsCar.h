//
// Created by Maia Sapunaru on 22.05.2025.
//

#ifndef SPORTSCAR_H
#define SPORTSCAR_H
#include "Car.h"


class SportsCar : public Car {
public:
    SportsCar(const std::string& name);
    float getScore() const override;
};



#endif //SPORTSCAR_H
