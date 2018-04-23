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

struct greitasMokinys{
    std::string pavarde{};
    std::string vardas{};
};
struct allMokinys{
    std::string pavarde{};
    std::string vardas{};
    std::vector<int> pazymiai;
};

extern const std::string iveskite;
extern const std::string baigti;
extern const std::string error;
extern const int exitnumber;
extern const double eweight;
extern const double pweight;
void grade (std::string ,std::string ,double ,double ,char );
void Checkforfiles(const std::string &);
int getInput(int  , int , int exit = INT_MAX);
int getInput2(int  , int , int exit = INT_MAX);
char aORb();
void generateStudentFile(std::string name,int length);
void splitbygrades(std::vector<greitasMokinys>&,std::vector<greitasMokinys>&);
void splitbygrades(std::deque<greitasMokinys>&,std::deque<greitasMokinys>&);
void splitbygrades(std::list<greitasMokinys>&,std::list<greitasMokinys>&);
void writetofile();

#endif //PAZYMIAI_PAZYM_H