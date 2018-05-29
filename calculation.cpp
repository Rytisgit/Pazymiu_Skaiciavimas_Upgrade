//
// Created by SuperPC on 4/23/2018.
//
#include "catch.hpp"
#include <algorithm>
#include <numeric>
#include "calculation.h"


double weightedmedian(std::vector<int> & inputvector,const double weight)
{
    std::sort(inputvector.begin(), inputvector.end());     // sort

    int tmedian{0};
    if (inputvector.size() % 2 == 0)           // even
        tmedian = (inputvector[inputvector.size() / 2 - 1] + inputvector[inputvector.size() / 2]) / 2;
    else                                // odd
        tmedian = inputvector[inputvector.size() / 2];

    return weight * tmedian;
}
TEST_CASE("weighted medians","[weightedmedian]"){
    std::vector<int> input{1,2,3};
    REQUIRE(weightedmedian(input,1)==2.0);

}
double weightedaverage(std::vector<int> & inputvector,const double weight)
{
    return weight * std::accumulate(inputvector.begin(),inputvector.end(),0.0) / inputvector.size();
}
double weightedaverage(const std::vector<int> & inputvector,const double weight) {
    return weight * std::accumulate(inputvector.begin(), inputvector.end(), 0.0) / inputvector.size();
}