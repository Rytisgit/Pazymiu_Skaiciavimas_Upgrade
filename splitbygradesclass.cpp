//
// Created by SuperPC on 4/16/2018.
//

#include "splitbygradesclass.h"

const double studentClass::galBalas(double (*func)(std::vector<int> &, double)) {
    checkvector();
    return ( func(pazymiai,1));

}
bool test(studentClass &Mok) {
    return Mok.galBalas() < 6;
}
