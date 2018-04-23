//
// Created by SuperPC on 4/23/2018.
//

#include <algorithm>
#include <numeric>
#include "calculation.h"

double weightedmedian(std::vector<int> & medi,const double weight)
{
    std::sort(medi.begin(), medi.end());     // sort

    int tmedian{};
    if (medi.size() % 2 == 0)           // even
        tmedian = (medi[medi.size() / 2 - 1] + medi[medi.size() / 2]) / 2;
    else                                // odd
        tmedian = medi[medi.size() / 2];

    return weight * tmedian;
}
double weightedaverage(std::vector<int> & temps,const double weight)
{
    return weight * std::accumulate(temps.begin(),temps.end(),0.0) / temps.size();
}
double weightedaverage(const std::vector<int> & temps,const double weight) {
    return weight * std::accumulate(temps.begin(), temps.end(), 0.0) / temps.size();
}