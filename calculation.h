//
// Created by SuperPC on 4/23/2018.
//

#ifndef PAZYMIAI_CALCULATION_H
#define PAZYMIAI_CALCULATION_H

#include <vector>
/// calculates a median from a given vector of ints, sorts the vector
/// \param weight a number to multiply with for the result
/// \return the median of the vector multiplied by the weight as a double for interchangeability with weightedaverage
double weightedmedian(std::vector<int> &inputvector, double weight = 0.4);
double weightedaverage(std::vector<int> &inputvector, double weight = 0.4);
/// calculates an average from a given vector of ints
/// \param weight a number to multiply with for the result
/// \return the average of the vector multiplied by the weight as a double
double weightedaverage(const std::vector<int> &inputvector, double weight = 0.4);
#endif //PAZYMIAI_CALCULATION_H
