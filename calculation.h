//
// Created by SuperPC on 4/23/2018.
//

#ifndef PAZYMIAI_CALCULATION_H
#define PAZYMIAI_CALCULATION_H

#include <vector>

double weightedmedian(std::vector<int> &, double weight = 0.4);
double weightedaverage(std::vector<int> &, double weight = 0.4);
double weightedaverage(const std::vector<int> &, double weight = 0.4);
#endif //PAZYMIAI_CALCULATION_H
