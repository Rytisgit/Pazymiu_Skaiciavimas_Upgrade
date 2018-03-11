//
// Created by SuperPC on 3/6/2018.
//

#ifndef PAZYMIAI_PAZYM_H
#define PAZYMIAI_PAZYM_H



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
double weightedmedian(std::vector<int> &, double weight = 0.4);
double weightedaverage(const std::vector<int> &, double weight = 0.4);
void grade (std::string ,std::string ,double ,double ,char );
int getInput(int  , int , int exit = INT_MAX);
char aORb();

#endif //PAZYMIAI_PAZYM_H