//
// Created by Maia Sapunaru on 22.05.2025.
//

#ifndef TUNEDSPORTSCAR_H
#define TUNEDSPORTSCAR_H
#include "SportsCar.h"


class TunedSportsCar : public SportsCar {
public:
    TunedSportsCar(const std::string& name, const float& speed, const float& fuel, const int& power);
    float getScore() const override;
};



#endif //TUNEDSPORTSCAR_H
