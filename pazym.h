//
// Created by SuperPC on 3/6/2018.
//

#ifndef PAZYMIAI_PAZYM_H
#define PAZYMIAI_PAZYM_H


#endif //PAZYMIAI_PAZYM_H
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
struct mokinys{
    std::string pavarde{};
    std::string vardas{};
    double vidurkis{};
    double medianas{};
};
const auto iveskite = "Iveskite skaiciu tarp 1 ir 10";
const auto baigti = " - Baigti Ivesti\n";
const int exitnumber = {-1};
const double eweight = 0.6;
const double pweight = 0.4;
int weightedmedian(std::vector<int> &, double weight = 0.4);
double weightedaverage(const std::vector<int> &, double weight = 0.4);
void grade (const std::string ,const std::string,const double,const int ,const char );
inline int getInput(const int min, const int max,const int exit = INT_MAX);
inline char aORb();

