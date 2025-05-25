//
// Created by Maia Sapunaru on 22.05.2025.
//

#ifndef SUV_H
#define SUV_H
#include "Car.h"


class SUV : public Car {
public:
    SUV(const std::string& name, const float& speed, );
    float getScore() const override;
};



#endif //SUV_H
