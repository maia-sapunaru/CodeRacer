//
// Created by Maia Sapunaru on 22.05.2025.
//

#ifndef CAR_H
#define CAR_H
#include<string>
#include<iostream>


class Car {
  static int carNumber;
  static float totalDistance;

  protected:
    std::string name;
    float speed;
    float fuel;
public:
    Car(const std::string& name, float fuel);
    virtual ~Car();


    static int getCarNumber();
    static float getTotalDistance();
    void addDistance(float km);

    virtual void accelerate(float amount);
    virtual void consumeFuel(float amount);

    virtual float getScore() const = 0;
    virtual void display(std::ostream& os) const;

    const std::string& getName() const;
    float getFuel() const;
    float getSpeed() const;

    friend std::ostream& operator<<(std::ostream& out, const Car& car);
};



#endif //CAR_H
