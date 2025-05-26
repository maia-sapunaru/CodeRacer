//
// Created by Maia Sapunaru on 26.05.2025.
//

#ifndef RACE_H
#define RACE_H
#include<vector>
#include<string>
#include "Car.h"

class Race {
    std::string raceName;
    std::vector<Car*> cars;
    float total;
public:
    Race(const std::string& raceName, const std::vector<Car*>& cars);

    float getScore() const;
    const std::string& getRaceName() const;
    const std::vector<Car*>& getCars() const;

    Car* getWinner() const;

    friend std::ostream& operator<<(std::ostream& os, const Race& race);
    };




#endif //RACE_H
