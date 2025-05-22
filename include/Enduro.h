//
// Created by Maia Sapunaru on 22.05.2025.
//

#ifndef ENDURO_H
#define ENDURO_H
#include "Car.h"


class Enduro : public Car {
public:
  Enduro(const std::string& name);
  float getScore() const override;
};



#endif //ENDURO_H
