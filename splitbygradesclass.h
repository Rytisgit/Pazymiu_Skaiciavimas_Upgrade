//
// Created by SuperPC on 4/16/2018.
//

#ifndef PAZYMIAI_SPLITBYGRADESCLASS_H
#define PAZYMIAI_SPLITBYGRADESCLASS_H


#include <string>
#include <vector>
#include <fstream>
#include <sstream>

class studentClass{
    std::string pavarde;
    std::string vardas;
    std::vector<int> pazymiai;

public:
    studentClass( std::string pav,  std::string var, std::vector<int> vec ) : pavarde(pav),vardas(var),pazymiai(vec){}
    studentClass( std::string pav,  std::string var) : pavarde(pav),vardas(var){}
    ~studentClass(){std::vector<int>().swap(pazymiai);}
    std::string getpavarde()const { return pavarde;}
    std::string getvardas()const { return pavarde;}
    std::vector getpazymiai()const { return pazymiai;}
};


#endif //PAZYMIAI_SPLITBYGRADESCLASS_H
