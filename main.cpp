#include <iostream>
#include<algorithm>
#include <vector>
#include <thread>
#include <chrono>

#include "../include/SportsCar.h"
#include "../include/TunedSportsCar.h"
#include "../include/SUV.h"
#include "../include/Enduro.h"
#include "../include/Economical.h"
#include "../include/Flexible.h"
#include "../include/Aggressive.h"
#include "../include/PavementTrack.h"
#include "../include/OffRoadTrack.h"
#include "../include/Raport.h"

int main() {
    std::vector<Car*> masini;
    std::vector<DrivingTechnique*> stiluri;
    Raport<Car> raportGeneral;

    int opt;
    do {
        std::cout << "\nCodeRacer - Simulator de curse cu masini\n";
        std::cout << "1. Adauga masina\n";
        std::cout << "2. Vezi cursa\n";
        std::cout << "3. Vezi raport general\n";
        std::cout << "0. Iesire\n";
        std::cout << "Optiune: ";
        std::cin >> opt;

        if (opt == 1) {
            std::string tipMasina;
            std::string nume;
            float viteza, combustibil;
            int putere;
            int stil;

            std::cout << "Ce tip de masina vrei sa adaugi? Optiuni: Masina sport, SUV, Enduro, Masina sport tunata. " << std::endl;
            std::cout << "Raspunsul tau: ";
            std::cin >> tipMasina;

            std::cout << "Introdu numele masinii tale: ";
            std::cin >> nume;
            std::cout << "Introdu viteza maxima pe care consideri ca o poate atinge masina ta: ";
            std::cin >> viteza;
            std::cout << "Introdu cantitatea de combustibil la plecare: ";
            std::cin >> combustibil;
            std::cout << "Introdu puterea masinii tale: ";
            std::cin >> putere;

            std::cout << "Alege un stil de condus (optiuni: 1-economic, 2-agresiv, 3-flexibil): ";
            std::cin >> stil;

            Car* m = nullptr;
            if (tipMasina == "sport")
                m = new SportsCar(nume, viteza, combustibil, putere);
            else if (tipMasina == "tuned")
                m = new TunedSportsCar(nume, viteza, combustibil, putere);
            else if (tipMasina == "suv")
                m = new SUV(nume, viteza, combustibil, putere);
            else if (tipMasina == "enduro")
                m = new Enduro(nume, viteza, combustibil, putere);
            else {
                std::cout << "Nu avem aceasta masina.\n";
                continue;
            }

            DrivingTechnique* dt = nullptr;
            if (stil == 1)
                dt = new Economical();
            else if (stil == 2)
                dt = new Aggressive();
            else if (stil == 3)
                dt = new Flexible();
            else {
                std::cout << "Nu avem acest stil.\n";
                delete m;
                continue;
            }

            masini.push_back(m);
            stiluri.push_back(dt);

        } else if (opt == 2) {
            if (masini.empty()) {
                std::cout << "Nicio masina in cursa!\n";
                continue;
            }

            Raport<Car> raportCursa;

            std::cout << "\nCURSA INCEPE\n";
            for (int sec = 1; sec <= 5; ++sec) {
                std::cout << "Secunda " << sec << " ---\n";

                for (int i = 0; i < masini.size(); i++) {
                    stiluri[i]->drive(*masini[i]);
                    raportCursa.add(masini[i]);
                    raportGeneral.add(masini[i]);
                }

                std::vector<Car*> clasament = masini;
                std::sort(clasament.begin(), clasament.end(), [](Car* a, Car* b) {
                    return a->getScore() > b->getScore();
                });

                int loc = 1;
                for (std::vector<Car*>::iterator it = clasament.begin(); it != clasament.end(); it++) {
                    Car* m = *it;
                    std::cout << loc++ << ". " << *m << " | Scor: " << m->getScore() << '\n';
                }


                std::this_thread::sleep_for(std::chrono::milliseconds(1000));
            }

            std::cout << "\nRAPORTUL CURSEI: \n"; // merge, dar nu imi place cum arata, voi reface
            raportCursa.showOrder();

        } else if (opt == 3) {
//de refacut aici
        }

    } while (opt != 0);

//MAI AM DE FACUT DEZALOCAREA

    return 0;
}
