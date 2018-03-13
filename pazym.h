//
// Created by SuperPC on 3/6/2018.
//

#ifndef PAZYMIAI_PAZYM_H
#define PAZYMIAI_PAZYM_H



#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include "randutils.hpp"
#include <deque>
#include <list>

struct mokinys{
    std::string pavarde{};
    std::string vardas{};
    double vidurkis{};
    double medianas{};
};

struct gerasMokinys{
    std::string pavarde{};
    std::string vardas{};
};
struct blogasMokinys{
    std::string pavarde{};
    std::string vardas{};
};
extern const std::string iveskite;
extern const std::string baigti;
extern const int exitnumber;
extern const double eweight;
extern const double pweight;
double weightedmedian(std::vector<int> &, double weight = 0.4);
double weightedaverage(const std::vector<int> &, double weight = 0.4);
void grade (std::string ,std::string ,double ,double ,char );
int getInput(int  , int , int exit = INT_MAX);
char aORb();
void generateStudentFile(std::string name,int length);
void splitbygrades(std::vector<gerasMokinys>&,std::vector<blogasMokinys>&);
void splitbygrades(std::deque<gerasMokinys>&,std::deque<blogasMokinys>&);
void splitbygrades(std::list<gerasMokinys>&,std::list<blogasMokinys>&);

#endif //PAZYMIAI_PAZYM_H