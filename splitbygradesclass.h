//
// Created by SuperPC on 4/16/2018.
//

#ifndef PAZYMIAI_SPLITBYGRADESCLASS_H
#define PAZYMIAI_SPLITBYGRADESCLASS_H


#include <string>
#include <vector>
#include <fstream>
#include <sstream>
#include "calculation.h"

class studentClass{
    std::string pavarde;
    std::string vardas;
    std::vector<int> pazymiai;
    void checkvector(){if(pazymiai.empty())throw std::invalid_argument("this doesnt have a vector");}
public:
    studentClass( std::string pav,  std::string var, std::vector<int> vec ) : pavarde(pav),vardas(var),pazymiai(vec){}
    studentClass( std::string pav,  std::string var) : pavarde(pav),vardas(var){}
    ~studentClass(){std::vector<int>().swap(pazymiai);}
    std::string getpavarde()const { return pavarde;}
    std::string getvardas()const { return vardas;}
    const double galBalas ( double (*) (std::vector<int>&,double )= weightedaverage);  // get'eriai
};

bool test(studentClass &Mok);
#endif //PAZYMIAI_SPLITBYGRADESCLASS_H
