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
extern const std::string iveskite;
extern const std::string baigti;
extern const int exitnumber;
extern const double eweight;
extern const double pweight;
int weightedmedian(std::vector<int> &, double weight = 0.4);
double weightedaverage(const std::vector<int> &, double weight = 0.4);
void grade (const std::string ,const std::string,const double,const int ,const char );
int getInput(const int min, const int max,const int exit = INT_MAX);
char aORb();

