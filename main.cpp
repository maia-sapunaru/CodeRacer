#include<iostream>
#include<fstream>
#include<vector>
#include<memory>
#include "Raport.h"
#include "SUV.h"
#include "SportsCar.h"
#include "TunedSportsCar.h"
#include "Enduro.h"
#include "Flexible.h"
#include "Aggressive.h"
#include "Economical.h"
#include "PavementTrack.h"
#include "OffRoadTrack.h"
std::ifstream fin("date_intrare.txt");



int main() {
    int nrCars;
    fin >> nrCars;

    std::vector<Car*> cars;

    for (int i = 0; i < nrCars; i++) {
        std::string type, name;
        float fuel, speed;
        int power;
        fin >> type >> name >> speed >> fuel >> power;


        //aici mai trebuie sa repar constructorii!!!
        Car* masina;
        if (type == "SUV") masina = new SUV(name, speed, fuel, power);
        else if (type == "Enduro") masina = new Enduro(name, speed, fuel, power);
        else if (type == "Masina sport") masina = new SportsCar(name, speed, fuel, power);
        else if (type == "Masina sport tunata") masina = new TunedSportsCar(name, speed, fuel, power);
    }

//aici mai urmeaza implementarea pt cursa.. piste..

Raport<Car> raport;
for (Car* car : cars)
    raport.add(car);
raport.showOrder();


return 0;


}