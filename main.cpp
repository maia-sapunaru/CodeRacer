#include <iostream>
#include<algorithm>
#include <vector>
#include <thread>
#include <chrono>
#include <Overheated.h>

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
#include "../include/Race.h"

int main() {
    std::vector<Car*> masini;
    std::vector<DrivingTechnique*> stiluri;
    Raport<Race> raport;
    static int nrCursa = 0;
    bool ok = false;

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
            else if (stil == 3) {
                dt = new Flexible();
                ok = true;
            }
            else {
                std::cout << "Nu avem acest stil.\n";
                delete m;
                continue;
            }

            masini.push_back(m);
            stiluri.push_back(dt);

        } else if (opt == 2) {
            nrCursa++;
            if (masini.empty()) {
                std::cout << "Nicio masina in cursa!\n";
                continue;
            }

            int nrCurbe;
            int varianta;
            bool schimbat = 0;
            std::string copie, vreme, tip;
            std::cout << "Ce fel de pista doresti pentru cursa? Optiunile sunt: asfalt sau off-road.\n" << "Raspunsul tau: ";
            std::cin >> tip;
            std::cout << "Introdu numarul de curbe al pistei: ";
            std::cin >> nrCurbe;
            std::cout << "Vrei ca vremea sa fie schimbata in mod aleatoriu pe parcursul cursei (1) sau sa fie constanta (2)?\n" << "Raspunsul tau: ";
            std::cin >> varianta;
            if (varianta == 1) {
                schimbat = 1;
                vreme = "sunny";
            }
            else if (varianta == 2) {
                std::cout << "Introdu vremea de pe pista. Optiunile sunt: insorit, innorat, ploios.  \n" << "raspunsul tau: ";
                std::cin >> copie;
                if (copie == "insorit")
                    vreme = "sunny";
                else if (copie == "innorat")
                    vreme = "cloudy";
                else if (copie == "ploios")
                    vreme = "rainy";
                else std::cout << "Nu e disponibila aceasta vreme.";
            }
            else
                std::cout << "Varianta indisponibila.";





            Track* pista = nullptr;
            if (tip == "asfalt")
                pista = new PavementTrack(nrCurbe, vreme);
            else if (tip == "off-road")
                pista = new OffRoadTrack(nrCurbe, vreme);
            else {
                std::cout << "Nu avem acest tip de pista!";
            }

            for (int i =0; i < (int)stiluri.size(); i++) {
                if (ok) {
                    Flexible* flex = dynamic_cast<Flexible*>(stiluri[i]);
                    if (flex != nullptr) {
                        flex -> updateFromTrack(*pista);
                    }
                }
            }
            Raport<Car> raportCursa;

            std::cout << "\nCURSA INCEPE\n";
            for (int sec = 1; sec <= 5; ++sec) {
                std::cout << "Secunda " << sec << " ---\n";

                try {
                    for (int i = 0; i < (int)masini.size(); i++) {
                        Car* masina = masini[i];

                        if (masina->isOverHeated() || masina->finishedFuel()) {
                            masina->resetScore();
                            continue;
                        }

                        stiluri[i]->drive(*masina);

                        if (masina -> getSpeed() > masina->getMaxSpeed()) {
                            masina->setOverheated(true);
                            throw Overheated("Masina " + masina->getName() + " s-a supraincalzit si a facut BOOM. Cursele s-au incheiat pe ziua de azi.");
                        }
                    }
                } catch (const Overheated& e) {
                    std::cout << "eroare";
                }




                std::vector<Car*> clasament = masini;
                std::sort(clasament.begin(), clasament.end(), [](Car* a, Car* b) {
                    return a->getScore() > b->getScore();
                });

                int loc = 1;
                for (std::vector<Car*>::iterator i = clasament.begin(); i != clasament.end(); i++) {
                    Car* m = *i;
                    std::cout << loc++ << ". " << *m << " | Scor: " << m->getScore() << '\n';



                    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
                }
                if (schimbat) pista -> randomWeather();
            }

            for (Car* m : masini) {
                raportCursa.add(m);
            }
            Race* cursa = new Race("Cursa " + std::to_string(nrCursa), masini);
            raport.add(cursa);


            std::cout << "\nRAPORTUL CURSEI: \n"; // merge, dar nu imi place cum arata, voi reface
            raportCursa.showOrder();
            delete pista;

        } else if (opt == 3) {
            std::cout << "\nRAPORTUL CURSELOR: \n";
            raport.showOrder();
        }

    } while (opt != 0);

    for(int i = 0; i < (int)masini.size(); i++) {
        delete masini[i];
    }
    masini.clear();
    for (int i = 0; i < (int)stiluri.size(); i++) {
        delete stiluri[i];
    }
    stiluri.clear();

    while (!raport.empty()) {
        delete raport.get();
        raport.removeTop();
    }



    return 0;
}

