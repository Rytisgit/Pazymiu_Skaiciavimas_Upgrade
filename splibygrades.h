//
// Created by SuperPC on 3/19/2018.
//

#ifndef PAZYMIAI_SPLIBYGRADES_H
#define PAZYMIAI_SPLIBYGRADES_H

#include <vector>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include "pazym.h"

template <typename T>
void printarray(const T &gMok){
    for (typename T::const_iterator i=gMok.begin(); i!=gMok.end(); ++i)
    {

        printf("%-15s%-15s\n", (i->pavarde).c_str(),(i->vardas).c_str());
//        std::string a = i->pavarde;
//        std::cout<<a<<std::endl;
    }

//    for (auto const &it : gMok)
//    {
//        printf("%-15s%-15s\n", it.pavarde.c_str(),it.vardas.c_str());
//    }
}
template <typename T>
void splitbygrades2(T & gMok, T &bMok) {
    std::vector<int> pazymiai{};
    int il{};
    std::string file{"f1"};
    std::string str{};
    std::string buf; // Have a buffer string
    std::vector<std::string> tokens; // Create vector to hold our words
    greitasMokinys tempmok;
    for (int i = 0; i < 5; ++i) {
        file+='0';
        std::ifstream f1(file);
        while(std::getline(f1, str)) { //read file until the end line by line

            std::stringstream ss (str);
            tokens.clear();
            while (ss >> buf) {
                tokens.push_back(buf);
            }
            for (int k = 0; k < 5; ++k) {
                std::stringstream s_str(tokens[k + 2]);
                s_str >> il;
                pazymiai.push_back(il);
            }
            tempmok.vardas = tokens[0];
          //a
            // a std::cout<<tokens[0];
            tempmok.pavarde = tokens[1];
            weightedaverage(pazymiai,1)<6 ? bMok.push_back(tempmok) : gMok.push_back(tempmok);
            pazymiai.clear();
        }
    }
}
#endif //PAZYMIAI_SPLIBYGRADES_H
