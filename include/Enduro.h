//
// Created by Maia Sapunaru on 22.05.2025.
//

#ifndef ENDURO_H
#define ENDURO_H
#include "Car.h"


class Enduro : public Car {
public:
  Enduro(const std::string& name, const float& speed, const float& fuel, const int& power);
  float getScore() const override;
};



#endif //ENDURO_H
